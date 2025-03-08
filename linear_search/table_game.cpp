#include <iostream>
#include <vector>
#include <algorithm>
#include <ranges>

int main(int argc, char const *argv[])
{
    int n, m;
    std::vector<std::pair<int, std::pair<int, int>>> v;
    std::cin >> n >> m;
    v.reserve(n * m);
    for (int i{}; i < n; ++i)
    {
        for (int j{}; j < m; ++j)
        {
            int a;
            std::cin >> a;
            v.emplace_back(a, std::make_pair(i, j));
        }
    }
    std::ranges::sort(v, std::greater<std::pair<int, std::pair<int, int>>>());
    auto it = v.begin(), ite = v.begin();
    auto [k, l] = it->second;
    while (it->second.first == k)
        ++it;
    while (ite->second.second == l)
        ++ite;
    if (it > ite)
        l = it->second.second;
    else if (ite > it)
        k = ite->second.first;
    else
    {
        if ((it+1)->second.first == k || (it+1)->second.second == it->second.second)
            l = it->second.second;
        else
            k = it->second.first;
    }

    std::cout << k + 1 << " " << l + 1 << std::endl;
    return 0;
}
