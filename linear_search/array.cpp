#include <iostream>
#include <vector>
#include <limits>

int split_array(int m)
{
    int min{std::numeric_limits<int>::max()};
    int n{}, k{1};
    std::vector<int> v;
    for (int i{}; i < m; ++i)
    {
        int a;
        std::cin >> a;
        if (min > a)
            min = a;
        if (n >= min)
        {
            v.push_back(n);
            n = 0;
            min = a;
        }
        ++n;
    }
    v.push_back(n);
    std::cout << v.size() << std::endl;
    for (auto &el : v)
        std::cout << el << " ";
    std::cout << std::endl;
    return 0;
}

int main(int argc, char const *argv[])
{
    int t;
    std::cin >> t;
    for (int i{}; i < t; ++i)
    {
        int n;
        std::cin >> n;
        split_array(n);
    }
    return 0;
}
