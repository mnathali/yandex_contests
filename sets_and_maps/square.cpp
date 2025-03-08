#include <iostream>
#include <set>
#include <vector>
#include <algorithm>

int main(int argc, char const *argv[])
{
    int n;
    std::set<std::pair<int, int>> points;
    std::vector<std::pair<int, int>> res;
    std::cin >> n;
    for (int i{}; i < n; ++i)
    {
        int a, b;
        std::cin >> a >> b;
        points.insert({a, b});
        if (i < 2)
            res.push_back({a, b});
    }
    for (auto it = points.begin(); n > 2 && it != points.end(); ++it)
    {
        for (auto ite = points.begin(); ite != points.end(); ++ite)
        {
            if (ite == it)
                continue;
            auto &p1 = *it, &p2 = *ite;
            std::vector<std::pair<int, int>> tmp{p1, p2};
            auto t1 = std::make_pair(p2.first - p2.second + p1.second, p2.second + p2.first - p1.first);
            auto t2 = std::make_pair(p1.first - p2.second + p1.second, p1.second + p2.first - p1.first);
            if (points.count(t1))
                tmp.push_back(t1);
            if (points.count(t2))
                tmp.push_back(t2);
            if (tmp.size() > res.size())
                res.swap(tmp);
        }
    }
    std::cout << 4 - res.size() << std::endl;
    if (res.size() == 1)
    {
        std::cout << res.begin()->first + 1 << " " << res.begin()->second << std::endl;
        res.push_back({res.begin()->first + 1, res.begin()->second});
    }
    auto it = res.begin();
    auto &p1 = *it;
    ++it;
    auto &p2 = *it;
    auto t1 = std::make_pair(p2.first - p2.second + p1.second, p2.second + p2.first - p1.first);
    auto t2 = std::make_pair(p1.first - p2.second + p1.second, p1.second + p2.first - p1.first);
    if (std::find(res.begin(), res.end(), t1) == res.end())
        std::cout << t1.first << " " << t1.second << std::endl;
    if (std::find(res.begin(), res.end(), t2) == res.end())
        std::cout << t2.first << " " << t2.second << std::endl;
    // std::cout << std::endl;
    // for (auto &el : res)
    //     std::cout << el.first << " " << el.second << std::endl;
    return 0;
}
