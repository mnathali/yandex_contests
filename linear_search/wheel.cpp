#include <iostream>
#include <vector>
#include <algorithm>

int main(int argc, char const *argv[])
{
    int n, a, b, k, max1{}, max2{};
    std::vector<int> v;
    std::cin >> n;
    v.reserve(n);
    for (int i{}; i < n; ++i)
    {
        int m;
        std::cin >> m;
        v.push_back(m);
    }
    std::cin >> a >> b >> k;
    int d1 = (a / k - (a % k == 0 && a / k ? 1 : 0)) % n, d2 = (b / k - (b % k == 0 && b / k ? 1 : 0)) % n;
    // std::cout << d1 << " " << d2 <<std::endl;
    if ((b / k - (b % k == 0 && b / k ? 1 : 0)) - (a / k - (a % k == 0 && a / k ? 1 : 0)) >= n)
        max1 = *(std::max_element(v.begin(), v.end()));
    else if (d2 < d1)
    {
        max1 = std::max(*std::max_element(v.begin(), v.begin() + d2 + 1),
                        *std::max_element(v.begin() + d1, v.end()));
        max2 = *std::max_element(v.rbegin() + d1, v.rend());
        if (d2)
            max2 = std::max(*std::max_element(v.rbegin(), v.rbegin() + d2), max2);
    }
    else
    {
        max1 = *std::max_element(v.begin() + d1, v.begin() + d2 + 1);
        if (d1 > 0)
            --d1;
        if (d2)
            max2 = *std::max_element(v.rbegin() + d1, v.rbegin() + d2);
    }
    max1 = std::max(max1, max2);
    std::cout << max1 << std::endl;
    return 0;
}
