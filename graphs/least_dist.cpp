#include <iostream>
#include <iterator>
#include <sstream>
#include <algorithm>
#include <vector>
#include <ranges>
#include <limits>

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
    int n, s, f, j;
    std::vector<std::vector<int>> v;
    std::vector<std::pair<bool, int>> paths;
    std::cin >> n >> s >> f;
    j = s - 1;
    std::cin.get();
    std::string str;
    std::stringstream ss;
    v.resize(n);
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
                paths[k].second = dist + edges[k];
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
    std::cout << (paths[f-1].second == std::numeric_limits<int>::max() ? -1 : paths[f-1].second) << std::endl;

    return 0;
}
