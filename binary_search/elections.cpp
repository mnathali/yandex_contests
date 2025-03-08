#include <iostream>
#include <vector>
#include <ranges>
#include <algorithm>

template<typename T, typename V>
std::ostream& operator<<(std::ostream& o, const std::pair<T, V>& pair)
{
    o << '{' << pair.first << ", " << pair.second << "}";
    return o;
}

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
    int n, max_bribe{0};
    std::vector<std::pair<std::pair<int, int>, int>> v;
    std::vector<long long> sums;
    std::cin >> n;
    v.reserve(n);
    sums.resize(n+1);
    for (auto i : std::views::iota(0, n))
    {
        std::pair<int, int> p;
        std::cin >> p.first >> p.second;
        v.push_back({p, i});
        if (p.second > max_bribe)
            max_bribe = p.second;
    }
    std::ranges::sort(v, [](auto &l, auto &r){
        if (l.first.first != r.first.first)
            return l.first.first < r.first.first;
        if (l.first.second != -1 && r.first.second != -1)
            return l.first.second < r.first.second;
        return l.first.second != -1;
    });
    for (int i{}; i < n; ++i)
        sums[i+1] += sums[i] + v[i].first.first;
    int min = v.back().first.first + max_bribe, index{}, pred{};
    for (int i{}; i < v.size(); ++i)
    {
        if (v[i].first.second != -1 && v[i].first.first != pred)
        {
            int l{i}, r = v.size() - 1, shift{};
            while (l < r - 1)
            {
                auto average = v[l + (r - l) / 2].first.first;
                if (v[i].first.first + sums[v.size()] - sums[l + (r - l) / 2] - (v.size() - (l + (r - l) / 2)) * v[l + (r - l) / 2].first.first > average)
                    l = l + (r - l) / 2;
                else
                    r = l + (r - l) / 2;
            }
            shift += sums[v.size()] - sums[r] - (v.size() - r) * v[r].first.first;
            int l1{v[l].first.first}, r1{v[r].first.first};
            while (l1 < r1 - 1)
            {
                auto step = (r1 - l1) / 2;
                if ((v.size() - r) * (step + v[r].first.first - r1) + v[i].first.first + shift
                > r1 - step)
                    l1 = r1 - step;
                else
                    r1 -= step;
            }
            shift += (v.size() - r) * (v[r].first.first - r1);
            int l2{0}, r2{static_cast<int>(v.size()) - r};
            while (l2 < r2 - 1)
            {
                if (l2 + (r2 - l2) / 2 + v[i].first.first + shift > r1)
                    r2 = l2 + (r2 - l2) / 2;
                else 
                    l2 += (r2 - l2) / 2;
            }
            shift += r2;
            if (shift + v[i].first.second - (i < r ? 0 : 1) < min)
            {
                min = shift + v[i].first.second - (i < r ? 0 : 1);
                index = i;
            }
        }
        pred = v[i].first.first;
    }

    std::cout << min << std::endl;
    std::cout << v[index].second + 1 << std::endl;
    int l{index}, r = v.size() - 1;
    while (l < r - 1)
    {
        auto average = v[l + (r - l) / 2].first.first;
        if (v[index].first.first + sums[v.size()] - sums[l + (r - l) / 2] - (v.size() - (l + (r - l) / 2)) * v[l + (r - l) / 2].first.first > average)
            l = l + (r - l) / 2;
        else
            r = l + (r - l) / 2;
    }
    v[index].first.first += sums[v.size()] - sums[r] - (v.size() - r) * v[r].first.first;
    for (int j{r+1}; j < v.size(); ++j)
        v[j].first.first = v[r].first.first;
    int l1{v[l].first.first}, r1{v[r].first.first};
    while (l1 < r1 - 1)
    {
        auto step = (r1 - l1) / 2;
        if ((v.size() - r) * (step + v[r].first.first - r1) + v[index].first.first
        > r1 - step)
            l1 = r1 - step;
        else
            r1 -= step;
    }
    v[index].first.first += (v.size() - r) * (v[r].first.first - r1);
    for (int j{r}; j < v.size(); ++j)
        v[j].first.first = r1;
    int l2{0}, r2{static_cast<int>(v.size()) - r};
    while (l2 < r2 - 1)
    {
        if (l2 + (r2 - l2) / 2 + v[index].first.first > r1)
            r2 = l2 + (r2 - l2) / 2;
        else 
            l2 += (r2 - l2) / 2;
    }
    v[index].first.first += r2;
    for (int j{}; j < r2; ++j)
        v[r + j].first.first -= 1;
    std::ranges::sort(v, [](auto &l, auto &r){ return l.second < r.second;});
    for (auto &el : v)
        std::cout << el.first.first << " ";
    std::cout << std::endl;

    return 0;
}