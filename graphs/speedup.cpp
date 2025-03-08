#include <iostream>
#include <vector>
#include <ranges>
#include <limits>
#include <map>
#include <list>

int main(int argc, char const *argv[])
{
    int n, k, A, B;
    std::vector<std::vector<std::pair<int, int>>> map;
    std::vector<std::pair<bool, long>> table;
    std::map<long, std::list<long>> paths;

    std::cin >> n >> k;
    table.resize(n, {false, std::numeric_limits<long>::max()});
    map.resize(n);
    for (auto _ : std::views::iota(0, k))
    {
        int a, b, l;
        std::cin >> a >> b >> l;
        map[a-1].emplace_back(b-1, l);
        map[b-1].emplace_back(a-1, l);
    }
    std::cin >> A >> B;
    long dist = 0;
    --A;
    table[A].second = 0;
    while (!table[B-1].first)
    {
        table[A].first = true;
        for (auto &road : map[A])
        {
            if (!table[road.first].first && road.second + dist < table[road.first].second)
            {
                table[road.first].second = road.second + dist;
                paths[road.second + dist].push_back(road.first);
            }
        }
        auto it = paths.begin();
        if (it == paths.end())
            break;
        A = it->second.back();
        dist = it->first;
        it->second.pop_back();
        if (it->second.empty())
            paths.erase(it);
    }
    std::cout << (table[B-1].first ? table[B-1].second : -1) << std::endl;
    return 0;
}
