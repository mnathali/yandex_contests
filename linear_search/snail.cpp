#include <iostream>
#include <vector>
#include <algorithm>
#include <ranges>

int main(int argc, char const *argv[])
{
    int n;
    long long max{}, sum{};
    std::vector<std::pair<std::pair<int, int>, int>> v;

    std::cin >> n;

    v.reserve(n);
    for (int i{}; i < n; ++i) {
        int a, b; 
        std::cin >> a >> b;
        v.push_back(std::make_pair(std::make_pair(a, b), i));
    }
    auto ite = std::partition(v.begin(), v.end(), [](auto &c) { 
        return c.first.first > c.first.second;});
    std::sort(v.begin(), ite, [](auto &l, auto &r){ return
        l.first.first - l.first.second + r.first.first > r.first.first - r.first.second + l.first.first;});
    if (ite != v.end())
    {
        auto max_it = std::max_element(ite, v.end());
        std::swap(*max_it, *ite);
    }

    for (auto it = v.begin(); it < v.end(); ++it)
    {
        sum += it->first.first;
        if (sum > max)
            max = sum;
        sum -= it->first.second;
    }
    std::cout << max << std::endl;
    for (auto &el : v)
        std::cout << el.second + 1 << " ";
    std::cout << std::endl;
    return 0;
}
