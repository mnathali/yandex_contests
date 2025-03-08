#include <iostream>
#include <ranges>
#include <limits>
#include <algorithm>
#include <vector>

int main(int argc, char const *argv[])
{
    int n, d, v, r;
    std::vector<std::vector<std::tuple<int, int, int>>> schadule;
    std::vector<std::pair<bool, int>> table;

    std::cin >> n >> d >> v >> r;
    schadule.resize(n);
    table.resize(n, {false, std::numeric_limits<int>::max()});
    for (auto _ : std::views::iota(0, r))
    {
        int a, t1, b, t2;
        std::cin >> a >> t1 >> b >> t2;
        schadule[a-1].emplace_back(b-1, t1, t2);
    }
    int original_time{};
    --d;
    table[d].second = 0;
    while (!table[v-1].first)
    {
        table[d].first = true;
        for (auto route : schadule[d])
        {
            if (auto [p, t_1, t_2] = route; t_1 >= original_time && t_2 < table[p].second)
                table[p].second = t_2;
        }
        auto it = std::min_element(table.begin(), table.end(), [](auto &l, auto &r)
                { if (!l.first && !r.first)
                    return l.second < r.second;
                  else
                    return !l.first;
                });
        if (it->first || it->second == std::numeric_limits<int>::max())
            break;
        original_time = it->second;
        d = it - table.begin();
    }
    std::cout << (table[v-1].first ? table[v-1].second : -1) << std::endl;
    
    return 0;
}
