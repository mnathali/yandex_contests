#include <iostream>
#include <vector>
#include <list>

template<typename T>
std::ostream& operator<<(std::ostream& o, const std::vector<T>& vec)
{
    o << '[';
    for (typename std::vector<T>::const_iterator it = vec.begin(); it < vec.end(); ++it)
        o << *it << ",";
    o << ']';
    return o;
}

int dfs_subtree_size(int node, int parent, std::vector<int> &sizes, const std::vector<std::vector<int>> &v) {
    sizes[node] = 1;
    for (int neighbor : v[node]) {
        if (neighbor != parent) {
            sizes[node] += dfs_subtree_size(neighbor, node, sizes, v);
        }
    }
    return sizes[node];
}

int look_diameter(int node, int parent, std::vector<bool> &on_diameter, const std::vector<std::vector<int>> &v, std::list<int> &lst) {
    if (on_diameter[node] == true)
    {
        lst.push_front(node);
        return true;
    }
    for (int neighbor : v[node]) {
        if (neighbor != parent) {
            on_diameter[node] = on_diameter[node] || look_diameter(neighbor, node, on_diameter, v, lst);
        }
    }
    if (on_diameter[node] == true)
        lst.push_front(node);
    return on_diameter[node];
}

int calculate_diameter(const std::vector<std::vector<int>> &v, int a, int exclude, int parent, int depth)
{
    int depth_max = depth;
    for (int neighbor : v[a]) {
        if (neighbor != parent && neighbor != exclude) {
            int tmp = calculate_diameter(v, neighbor, exclude, a, depth+1);
            depth_max = depth_max > tmp ? depth_max : tmp;
        }
    }
    return depth_max;
}

int find_point(int n, int last1, const std::vector<std::vector<int>> &v, int exclude)
{
    std::vector<bool> visited;
    std::list<int> lst;
    visited.resize(n);
    lst.push_back(last1);
    while (!lst.empty())
    {
        auto index = lst.front();
        lst.pop_front();
        visited[index] = true;
        last1 = index;
        for (int j{}; j < v[index].size(); ++j)
            if (visited[v[index][j]] == false && v[index][j] != exclude)
                lst.push_back(v[index][j]);
    }
    return last1;
}

int main(int argc, char const *argv[])
{
    int n;
    std::cin >> n;

    std::vector<std::vector<int>> v;
    v.resize(n);
    
    for (int i{}; i < n-1; ++i)
    {
        int a, b;
        std::cin >> a >> b;
        v[a - 1].push_back(b - 1);
        v[b - 1].push_back(a - 1);
    }
    int last1 = find_point(n, 0, v, -1);
    int last2 = find_point(n, last1, v, -1);
    std::vector<int> sizes(n);
    sizes[last1] += 1;
    for (int i{}; i < v[last1].size(); ++i)
        sizes[last1] += dfs_subtree_size(v[last1][i], last1, sizes, v);
    std::vector<bool> on_diameter(n);
    on_diameter[last1] = on_diameter[last2] = true;
    std::list<int> lst;
    for (int i{}; i < v[last1].size(); ++i)
        look_diameter(v[last1][i], last1, on_diameter, v, lst);
    lst.push_front(last1);
    int index = lst.front(), prev = lst.front();
    int mul = 0;
    int diameter = calculate_diameter(v, last1, -1, -1, 0);
    bool index_on = false, prev_on = false;
    int prev_d, index_d;
    while (index != last2)
    {
        prev = index;
        lst.pop_front();
        index = lst.front();
        index_d = calculate_diameter(v, last2, prev, -1, 0);
        prev_d = calculate_diameter(v, last1, index, -1, 0);
        auto tmp = prev_d * index_d;
        if (mul < tmp)
        {
            mul = tmp;
        }
    }
    for (int i{}; i < n; ++i)
    {
        if (!on_diameter[i] && (sizes[i] - 1) * diameter > mul)
        {
            for (int j{}; j < v[i].size(); ++j)
            {
                if (on_diameter[v[i][j]])
                {
                    auto tmp = calculate_diameter(v, find_point(n, i, v, v[i][j]), v[i][j], -1, 0) * diameter;
                    if (tmp > mul)
                        mul = tmp;
                }
            }
        }
    }
    std::cout << mul << std::endl;
    return 0;
}
