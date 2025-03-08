#include <iostream>
#include <vector>
#include <algorithm>

template<typename T>
std::ostream& operator<<(std::ostream& o, const std::vector<T>& vec)
{
    o << '[';
    for (typename std::vector<T>::const_iterator it = vec.begin(); it < vec.end(); ++it)
        o << *it << ",";
    o << ']';
    return o;
}

int main(int argc, char const *argv[])
{
    int n, m, k;
    std::cin >> n;
    std::vector<int> a, b, sums, ends1, ends2;
    a.reserve(n);
    ends1.resize(n, 0);
    ends2.resize(n, 0);
    sums.reserve(n);
    b.resize(n, 0);
    for (int i{}; i < n; ++i)
    {
        int val;
        std::cin >> val;
        a.push_back(val);
    }
    std::cin >> m >> k;
    for (int i{}; i < n - 1; ++i)
    {
        if (a[i] == a[i+1])
            b[i] = 1;
    }
    sums.push_back(b.back());
    for (int i{1}; i < n; ++i)
        sums.push_back(sums.back() + b[n - 1 - i]);
    auto rit_a = a.rbegin(), rit_b = a.rbegin();
    while (rit_b != a.rend())
    {
        if (sums[rit_b - a.rbegin()] - sums[rit_a - a.rbegin()] <= k)
            ++rit_b;
        else
        {
            ends1[n - 1 - (rit_a - a.rbegin())] = n - (rit_b - a.rbegin());
            ++rit_a;
        }
    }
    //std::cout << b << std::endl;
    //std::cout << sums << std::endl;
    //std::cout << ends1 << std::endl;
    auto it_a = a.begin(), it_b = a.begin();
    while (it_b != a.end())
    {
        ends2[it_b - a.begin()] = it_a - a.begin();
        auto tmp = it_b;
        ++it_b;
        if (it_b != a.end() && *tmp > *it_b)
            it_a = it_b;
    }
    //std::cout << ends2 << std::endl;
    for (int i{}; i < m; ++i)
    {
        int val;
        std::cin >> val;
        std::cout << std::max(ends1[val - 1], ends2[val - 1]) + 1 << " ";
    }
    std::cout << std::endl;
    return 0;
}
