#include <iostream>
#include <ranges>
#include <algorithm>
#include <vector>


template<typename T>
std::ostream& operator<<(std::ostream& o, const std::vector<T>& vec)
{
    // o << '[';
    for (typename std::vector<T>::const_iterator it = vec.begin(); it < vec.end(); ++it)
        o << *it+1 << " ";
    // o << ']';
    return o;
}

int main(int argc, char const *argv[])
{
    int n;
    int res{};
    std::vector<std::vector<int>> v;
    std::vector<bool> res_p;

    std::cin >> n;
    v.resize(n);
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
    for (int i = 1; i < n; ++i)
    {
        std::vector<bool> status(n - i, false);
        std::vector<bool> tail(i, true);
        status.insert(status.end(), tail.begin(), tail.end());
        int max = res;
        while(std::next_permutation(status.begin(), status.end()))
        {
            int tmp{};
            for (int k = 0; k < n; ++k)
            {
                for (int j = 0; status[k] && j < n; ++j)
                    if (!status[j])
                        tmp += v[k][j];
            }
            if (tmp > res)
            {
                res_p = status;
                res = tmp;
            }
        }
        if (max == res)
            break;
    }
    std::cout << res << std::endl;
    std::cout << res_p << std::endl;
    return 0;
}
