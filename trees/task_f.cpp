#include <iostream>
#include <vector>

template<typename T>
std::ostream& operator<<(std::ostream& o, const std::vector<T>& vec)
{
    for (typename std::vector<T>::const_iterator it = vec.begin(); it < vec.end(); ++it)
        o << *it << " ";
    return o;
}

int how_much(int index, std::vector<std::vector<int>> &v, std::vector<unsigned long long> &res)
{
    unsigned long long count{1};
    int n{1};
    for (int i{}; i < v[index].size(); ++i)
    {
        int n_in_branch{0};
        n_in_branch = how_much(v[index][i], v, res);
        count += res[v[index][i]] + n_in_branch;
        n += n_in_branch;
    }
    res[index] = count;
    return n;
}

int main(int argc, char const *argv[])
{
    int n;
    std::cin >> n;
    std::vector<std::vector<int>> v;
    std::vector<unsigned long long> res;

    v.resize(n);
    res.resize(n);

    for (int i{1}; i < n; ++i)
    {
        int val;
        std::cin >> val;
        v[val - 1].push_back(i);
    }    

    how_much(0, v, res);
    std::cout << res << std::endl;

    return 0;
}
