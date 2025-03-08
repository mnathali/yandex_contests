#include <iostream>
#include <set>
#include <vector>

int main(int argc, char const *argv[])
{
    int n, k;

    std::vector<int> v;
    std::vector<int> p;
    std::set<std::pair<int, int>> s;

    std::cin >> n >> k;
    v.resize(n);
    p.resize(n);
    for (int i{}; i < n; ++i)
        std::cin >> v[i];
    int price = v[0], index = 0;
    int total_price{};
    for (int i{}; i < n; ++i)
    {
        s.insert({v[i], i});
        if (i - k >= 0)
        {
            auto it = s.find({v[i-k], i-k});
            if (it != s.end())
                s.erase(it);
        }
        if (i - index >= k && !s.empty())
        {
            price = s.begin()->first;
            index = s.begin()->second;
        }
        if (v[i] < price)
        {
            price = v[i];
            index = i;
        }
        ++p[index];
        total_price += price;
    }
    std::cout << total_price << std::endl;
    for (auto &el : p)
        std::cout << el << " ";
    std::cout << std::endl;
    return 0;
}
