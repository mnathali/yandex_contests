#include <iostream>
#include <vector>
#include <algorithm>
#include <stdlib.h>
#include <map>

template<typename T>
std::ostream& operator<<(std::ostream& o, const std::vector<T>& vec)
{
    o << '[';
    for (typename std::vector<T>::const_iterator it = vec.begin(); it < vec.end(); ++it)
        o << *it << ",";
    o << ']';
    return o;
}
template<typename T, typename V>
std::ostream& operator<<(std::ostream& o, const std::pair<T, V>& pair)
{
        o << "{" << pair.first << ", " << pair.second << "}";
    return o;
}

int main(int argc, char const *argv[])
{
    int n, h;
    std::vector<std::pair<int, unsigned long long>> hw;
    std::vector<int> sum;
    std::map<int, int, std::greater<int>> mp;
    std::cin >> n >> h;
    hw.reserve(n);
    sum.reserve(n+1);
    sum.push_back(0);
    for (int i{}; i < n; ++i)
    {
        int val;
        std::cin >> val;
        hw.push_back({val, 0});
    }
    for (int i{}; i < n; ++i)
    {
        int val;
        std::cin >> val;
        hw[i].second = val;
    }
    std::sort(hw.begin(), hw.end());
    for (int i{}; i < n; ++i)
        sum.push_back(sum.back() + hw[i].second);
    auto it1 = hw.begin(), it2 = hw.begin();
    int min_comfort = std::abs(hw.front().first - hw.back().first);
    int current_h = it1->second;
    while (it2 != hw.end())
    {
        if (current_h < h)
        {
            ++it2;
            if (it2 != hw.end())
            {
                auto new_comfort = std::abs(it2->first - (it2-1)->first);
                mp[new_comfort] += 1;
                current_h = sum[it2 - hw.begin() + 1] - sum[it1 - hw.begin()];
            }
        }
        else if (it1 != it2)
        {
            min_comfort = std::min(min_comfort, mp.begin()->first);
            auto remove_comfort = std::abs(it1->first - (it1+1)->first);
            auto it_comfort = mp.find(remove_comfort);
            it_comfort->second -= 1;
            if (it_comfort->second == 0)
                mp.erase(it_comfort);
            ++it1;
            current_h = sum[it2 - hw.begin() + 1] - sum[it1 - hw.begin()];
        }
        else
        {
            min_comfort = 0;
            break;
        }
    }
    std::cout << min_comfort << std::endl;
    return 0;
}
