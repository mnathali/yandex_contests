#include <iostream>
#include <vector>
#include <ranges>
#include <limits>
#include <list>
#include <algorithm>
#include <iomanip>
#include <queue>


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
    int n;
    std::list<int> indexes;
    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> dists;
    std::vector<std::pair<int, int>> city_sets;
    std::vector<std::vector<std::pair<int, int>>> roads;
    std::vector<int> prevs;
    std::vector<int> distances;
    std::vector<std::pair<bool, double>> table;
    std::cin >> n;
    table.resize(n, {false, 0});
    prevs.resize(n);
    distances.resize(n);
    city_sets.reserve(n);
    roads.resize(n);
    indexes.push_back(0);
    for (auto _ : std::views::iota(0, n))
    {
        int t, v;
        std::cin >> t >> v;
        city_sets.emplace_back(t, v);
    }
    for (auto _ : std::views::iota(0, n-1))
    {
        int a, b, s;
        std::cin >> a >> b >> s;
        roads[a-1].emplace_back(b-1, s);
        roads[b-1].emplace_back(a-1, s);
    }
    table[0].second = 0;

    while (!indexes.empty())
    {
        int pos = indexes.front();
        table[pos].first = true;
        for (auto &road : roads[pos])
        {
            auto [p, s] = road;
            if (!table[p].first && p != 0)
            {
                indexes.push_back(p);
                distances[p] = distances[pos] + s;
                dists.emplace(distances[p], p);
                if (city_sets[p].first + (double)distances[p] / city_sets[p].second 
                    < city_sets[p].first + (double)s / city_sets[p].second + table[pos].second)
                        table[p].second = city_sets[p].first + (double)distances[p] / city_sets[p].second;
                else
                {
                    table[p].second = city_sets[p].first + (double)s / city_sets[p].second + table[pos].second;
                    prevs[p] = pos;
                }
            }
        }
        indexes.pop_front();
    }
    for (auto init : std::views::iota(1, n))
    {
        // init = dists.top().second;
        // dists.pop();
        std::vector<int> distances_c(n);
        std::vector<std::pair<bool, double>> table_c(n, {false, 0});
        table_c[init].second = 0;
        indexes.push_back(init);
        while (!indexes.empty())
        {
            int pos = indexes.front();
            table_c[pos].first = true;
            for (auto &road : roads[pos])
            {
                auto [p, s] = road;
                if (!table_c[p].first)
                {
                    indexes.push_back(p);
                    distances_c[p] = distances_c[pos] + s;
                    if (city_sets[p].first + (double)distances_c[p] / city_sets[p].second 
                        < city_sets[p].first + (double)s / city_sets[p].second + table_c[pos].second)
                        {
                            table_c[p].second = city_sets[p].first + (double)distances_c[p] / city_sets[p].second;
                            if (table_c[p].second + table[init].second < table[p].second)
                            {
                                table[p].second = table_c[p].second + table[init].second;
                                prevs[p] = init;
                            }
                        }
                    else
                    {
                        table_c[p].second = city_sets[p].first + (double)s / city_sets[p].second + table_c[pos].second;
                        if (table_c[p].second + table[init].second < table[p].second)
                        {
                            table[p].second = table_c[p].second + table[init].second;
                            prevs[p] = pos;
                        }
                    }
                }
            }
            indexes.pop_front();
        }
    }
    for (auto init : std::views::iota(1, n))
    {
        init = dists.top().second;
        dists.pop();
        std::vector<int> distances_c(n);
        std::vector<std::pair<bool, double>> table_c(n, {false, 0});
        table_c[init].second = 0;
        indexes.push_back(init);
        while (!indexes.empty())
        {
            int pos = indexes.front();
            table_c[pos].first = true;
            for (auto &road : roads[pos])
            {
                auto [p, s] = road;
                if (!table_c[p].first)
                {
                    indexes.push_back(p);
                    distances_c[p] = distances_c[pos] + s;
                    if (city_sets[p].first + (double)distances_c[p] / city_sets[p].second 
                        < city_sets[p].first + (double)s / city_sets[p].second + table_c[pos].second)
                        {
                            table_c[p].second = city_sets[p].first + (double)distances_c[p] / city_sets[p].second;
                            if (table_c[p].second + table[init].second < table[p].second)
                            {
                                table[p].second = table_c[p].second + table[init].second;
                                prevs[p] = init;
                            }
                        }
                    else
                    {
                        table_c[p].second = city_sets[p].first + (double)s / city_sets[p].second + table_c[pos].second;
                        if (table_c[p].second + table[init].second < table[p].second)
                        {
                            table[p].second = table_c[p].second + table[init].second;
                            prevs[p] = pos;
                        }
                    }
                }
            }
            indexes.pop_front();
        }
    }
    auto it = std::max_element(table.begin(), table.end(), [](auto &l, auto &r){return l.second < r.second;});
    std::cout << std::fixed << std::setprecision(6);
    std::cout << it->second << std::endl;

    int start = it - table.begin();
    for (int i = it - table.begin(); i != 0;)
    {
        std::cout << i + 1 << " ";
        i = prevs[i];
    }
    std::cout << 1 << std::endl;
    return 0;
}
