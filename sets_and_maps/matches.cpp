#include <iostream>
#include <set>
#include <cmath>
#include <map>

int main(int argc, char const *argv[])
{
    int n, max{};
    std::set<std::pair<std::pair<int, int>, std::pair<int, int>>> st1;
    std::set<std::pair<std::pair<int, int>, std::pair<int, int>>> st2;
    std::map<std::pair<int, int>, int> mp;
    std::map<std::pair<int, int>, std::pair<int, int>> mp_point;

    std::cin >> n;

    for (int i{}; i < n; ++i)
    {
        std::pair<std::pair<int, int>, std::pair<int, int>> l1;
        std::cin >> l1.first.first >> l1.first.second >> l1.second.first >> l1.second.second;
        st1.insert(l1);
        std::swap(l1.second, l1.first);
        st1.insert(l1);
    }
    for (int i{}; i < n; ++i)
    {
        std::pair<std::pair<int, int>, std::pair<int, int>> l1;
        std::cin >> l1.first.first >> l1.first.second >> l1.second.first >> l1.second.second;
        st2.insert(l1);
        std::swap(l1.second, l1.first);
        st2.insert(l1);
    }
    for (auto it = st2.begin(); it != st2.end(); ++it)
    {
        for (auto ite = st1.begin(); ite != st1.end(); ++ite)
        {
            if ((it->first.first - it->second.first) * (it->first.second - it->second.second) == 
                (ite->first.first - ite->second.first) * (ite->first.second - ite->second.second) 
                && std::abs(it->first.first - it->second.first) == std::abs(ite->first.first - ite->second.first))
                {
                    auto &p1 = it->first.second > it->second.second ? it->first : it->second;
                    auto &p2 = ite->first.second > ite->second.second ? ite->first : ite->second;
                    auto d = std::make_pair(p1.first - p2.first, p1.second - p2.second);
                    mp[d] += 1;
                    mp_point[d] = p1;
                }
        }
    }
    auto f_el = st2.begin()->first;
    int m{1};
    for (auto &el : mp)
    {
        if (el.second > m)
        {
            m = el.second;
            f_el = mp_point[el.first];
        }
    }
    for (auto &l : st1)
    {
        auto delta_x = l.first.first - f_el.first;
        auto delta_y = l.first.second - f_el.second;
        int tmp{};
        for (auto &l2 : st2)
        {
            if (st1.count(std::pair<std::pair<int, int>, std::pair<int, int>>{
                {l2.first.first+delta_x, l2.first.second+delta_y},
                {l2.second.first+delta_x, l2.second.second+delta_y}}))
                ++tmp;
        }
        if (tmp > max)
            max = tmp;
    }
    std::cout << (st2.size() - max) / 2 << std::endl;
    return 0;
}
