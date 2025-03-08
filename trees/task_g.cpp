#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>

unsigned long long MOD = 1000000007;

template<typename T>
std::ostream& operator<<(std::ostream& o, const std::vector<T>& vec)
{
    o << '[';
    for (typename std::vector<T>::const_iterator it = vec.begin(); it < vec.end(); ++it)
        o << *it << ",";
    o << ']';
    return o;
}

unsigned long long factorial(int n) {
    unsigned long long result = 1;
    for (int i = 2; i <= n; ++i) {
        result = (result * i);
        result %= MOD;
    }
    return result;
}

// unsigned long long countArrangements(int n, int m) {
//     std::vector<unsigned long long> prev(m + 1, 0);
//     std::vector<unsigned long long> curr(m + 1, 0);

//     for (int j = 0; j <= m; ++j) {
//         prev[j] = 1;
//     }

//     for (int i = 1; i <= n; ++i) {
//         curr[0] = 0;
//         for (int j = 1; j <= m; ++j) {
//             curr[j] = curr[j - 1] + prev[j];
//             curr[j] %= MOD;
//             prev[j] = curr[j];
//         }
//     }

//     return curr[m];
// }
// unsigned long long countArrangements(int n, int m) {
//     if (n == 0 || m == 1) return 1;
//     if (m == 0) return 0;
//     unsigned long long total = 0;
//     for (int k = n; k >= 0; --k) {
//         total += countArrangements(n - k, m - 1);
//     }
//     return total;
// }
unsigned long long piece_of_factorial(int k, int n)
{
    unsigned long long result = 1;
    for(int t1 = k, t2 = n; t1 > 0; --t1, --t2)
    {
        result = result * t2;
        result %= MOD;
    }
    return result;
}

unsigned long long countArrangements(int n, int m) {

    return piece_of_factorial(n, n + m - 1);
}


void look_group(int current, const std::vector<std::vector<int>> &v, std::vector<bool> &visited,
    std::vector<std::vector<int>> &groups, bool &is_cycle)
{
    visited[current] = true;
    groups.back().push_back(current);
    int count{0};
    for (int i{0}; i < v[current].size(); ++i)
    {
        if (!visited[v[current][i]])
            look_group(v[current][i], v, visited, groups, is_cycle);
        else
            count += 1;
    }
    is_cycle = count > 1;
}

void more_than_two(int parent, int exclude, const std::vector<std::vector<int>> &v, bool &is_more, int &free_elements)
{
    int count {};
    int next_index{-1};
    int local_free_elements{};
    for (auto child: v[parent])
    {
        if (v[child].size() > 1 && child != exclude)
        {
            count += 1;
            next_index = child;
        }
        else if (child != exclude)
        {
            local_free_elements += 1;
            free_elements *= local_free_elements;
            free_elements %= MOD;
        }
        if (count > 1)
        {
            is_more = true;
            return;
        }
    }
    if (next_index != -1 && !is_more)
        more_than_two(next_index, parent, v, is_more, free_elements);
}


int main(int argc, char const *argv[])
{
    int n, m, k;
    std::cin >> n >> m >> k;
    MOD = k;
    std::vector<std::vector<int>> v;
    std::vector<int> in_group;
    std::vector<std::vector<int>> groups;
    std::vector<bool> visited;
    visited.resize(n);
    v.resize(n);
    for (int i{}; i < m; ++i)
    {
        int a, b;
        std::cin >> a >> b;
        v[a-1].push_back(b-1);
        v[b-1].push_back(a-1);
    }
    bool is_cycle = false;
    for (int i{}; i < n; ++i)
    {
        if (visited[i] == false)
        {
            groups.push_back({i});
            visited[i] = true;
            for (int j{}; j < v[i].size(); ++j)
            {
                look_group(v[i][j], v, visited, groups, is_cycle);
            }
        }
    }
    if (is_cycle)
    {
        std::cout << 0 << std::endl;
        return 0;
    }
    in_group.resize(groups.size());
    int alones{};
    for (int i{}; i < groups.size(); ++i)
    {
        if (groups[i].size() == 1)
            alones += 1;
        for (int j{}; j < groups[i].size(); ++j)
        {
            bool is_more = false;
            int free_elements = 1;
            int next_index{-1};
            int parent = groups[i][j];
            int exclude = -1;
            do {
                int local_free_elements{};
                int count {};
                next_index = -1;
                for (auto child: v[parent])
                {
                    if (v[child].size() > 1 && child != exclude)
                    {
                        count += 1;
                        next_index = child;
                    }
                    else if (child != exclude)
                    {
                        local_free_elements += 1;
                        free_elements *= local_free_elements;
                        free_elements %= MOD;
                    }
                    if (count > 1)
                    {
                        is_more = true;
                    }
                }
                exclude = parent;
                parent = next_index;
            } while (!is_more && next_index != -1);
            if (!is_more)
            {
                in_group[i] += free_elements;
            }
        }
    }
    // std::cout << in_group << std::endl;
    unsigned long long res{1};
    res *= factorial(groups.size() - alones);
    for (auto mul: in_group)
    {
        res *= mul;
        res %= MOD;
    }
    // std::cout << alones << " " << n - alones + 2 << std::endl;
    if (res != 0 && alones > 0)
        res *= countArrangements(alones, n - alones + 2);
    res %= MOD;
    // res *= factorial(alones);
    // res %= MOD;
    std::cout << res << std::endl;
    return 0;
}
