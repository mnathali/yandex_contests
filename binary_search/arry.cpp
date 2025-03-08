#include <iostream>
#include <vector>
#include <ranges>
#include <algorithm>

int b_search(std::vector<int> &v, int a, std::string_view s)
{
    int l = 0, r = v.size() - 1;

    while (v[l + (r-l)/2] != a && (r-l)/2)
    {
        if (v[l + (r-l)/2] > a)
            r = l + (r - l) / 2;
        else
            l = l + (r - l) / 2;
    }
    if (s == "max")
    {
        while (r >= 0 && v[r] > a)
            --r;
        return r;
    }
    while (l < r && v[l] < a)
        ++l;
    return l;
}

int main(int argc, char const *argv[])
{
    int n, k;

    std::cin >> n;
    std::vector<int> v(n);
    for (int i{}; i < n; ++i)
        std::cin >> v[i];
    std::cin >> k;
    std::ranges::sort(v);
    for (int i{}; i < k; ++i)
    {
        int a, b;
        std::cin >> a >> b;
        int r = b_search(v, b, "max"), l = b_search(v, a, "min");
        auto res = r - l + (v[l] >= a && v[l] <= b || v[r] >= a && v[r] <= b ? 1 : 0);
        std::cout << (res < 0 ? 0 : res) << " ";
    }

    return 0;
}
