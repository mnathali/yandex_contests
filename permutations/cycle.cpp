#include <iostream>
#include <vector>
#include <ranges>

template<typename T>
std::ostream& operator<<(std::ostream& o, const std::vector<T>& vec)
{
    // o << '[';
    for (typename std::vector<T>::const_iterator it = vec.begin(); it < vec.end(); ++it)
        o << *it+1 << " ";
    // o << ']';
    return o;
}

bool has_connection(std::vector<std::vector<int>> &v, int i, int j)
{
    return v[i][j];
}

void recursive(std::vector<std::vector<int>> &v, std::vector<int> &status, int n, int d, int &res)
{
    if (d == n-1)
    {
        
        int tmp{v[0][status[0]] + v[0][status[d - 1]]};
        for (int i = 0, j = 1; j < d; ++i, ++j)
            tmp += v[status[i]][status[j]];
        if (tmp < res)
            res = tmp;
        // std::cout << status << std::endl;
        return;
    }
    for (int i = 1; i < n; ++i)
    {
        int step{};
        for (int j = 0; !step && j < d; ++j)
            if (status[j] == i)
                ++step;
        if (step || !has_connection(v, i, (d > 0 ? status[d-1] : 0)) || d == n - 2 && !has_connection(v, i, 0))
            continue;
        status[d] = i;
        recursive(v, status, n, d + 1, res);
    }
}


int main(int argc, char const *argv[])
{
    int n;
    int res{2147483647};
    std::vector<std::vector<int>> v;
    std::vector<int> status;

    std::cin >> n;
    v.resize(n);
    status.resize(n-1);
    for (auto i : std::views::iota(0,n))
    {
        v[i].reserve(n);
        for (auto _ : std::views::iota(0,n))
        {
            int t;
            std::cin >> t;
            v[i].push_back(t);
        }
    }
    if (n - 1)
        recursive(v, status, n, 0, res);
    else
        res = 0;
    std::cout << (res == 2147483647 ? -1 : res) << std::endl;
    return 0;
}
