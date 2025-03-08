#include <iostream>
#include <iterator>
#include <sstream>
#include <algorithm>
#include <vector>
#include <ranges>
#include <limits>

int main(int argc, char const *argv[])
{
    int n, s, f, j;
    std::vector<std::vector<int>> v;
    std::vector<int> prevs;
    std::vector<std::pair<bool, int>> paths;
    std::cin >> n >> s >> f;
    j = s - 1;
    std::cin.get();
    std::string str;
    std::stringstream ss;
    v.resize(n);
    prevs.resize(n, -1);
    paths.resize(n, std::pair(false, std::numeric_limits<int>::max()));
    paths[j].second = 0;
    paths[j].first = true;
    for (int i = 0; i < n; ++i)
    {
        v[i].reserve(n);
        std::getline(std::cin, str);
        ss << str;
        std::copy(std::istream_iterator<int>(ss), std::istream_iterator<int>(), std::back_inserter(v[i]));
        ss.clear();
    }
    int dist = 0;
    for (int i = 0; i < n; ++i)
    {
        std::vector<int> &edges = v[j];
        paths[j].first = true;
        for (int k = 0; k < n; ++k)
        {
            if (edges[k] > 0 && dist + edges[k] < paths[k].second)
            {
                paths[k].second = dist + edges[k];
                prevs[k] = j;
            }
        }
        auto it = std::min_element(paths.begin(), paths.end(), [](auto &l, auto &r)
                { if (!l.first && !r.first)
                    return l.second < r.second;
                  else
                    return !l.first;
                });
        dist = it->second;
        j = it - paths.begin();
    }
    std::vector<int> res;
    if (prevs[f-1] == -1)
        if (s != f)
            std::cout << -1;
        else
            ;
    else
    {
        for (int i = f-1; i != s-1;)
        {
            res.push_back(i + 1);
            i = prevs[i];
        }
        res.push_back(s);
        for (auto it = res.rbegin(); it != res.rend(); ++it)
            std::cout << *it << " ";
    }
    std::cout << std::endl;
    return 0;
}
