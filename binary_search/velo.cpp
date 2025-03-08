#include <iostream>
#include <vector>
#include <ranges>
#include <algorithm>

int vertical_first(std::pair<int, int> base, std::vector<std::pair<int, int>> &v, int p)
{
    int j{};
    auto view = v | std::views::filter([&base, p](auto &el){
    return !(base.first <= el.first && base.first + p > el.first);});
    for (auto &el : view)
    {
        ++j;
        break;
    }
    if (j == 0)
        return 0;
    auto min = std::ranges::min_element(view, [](auto &l, auto &r){return l.second < r.second;});
    auto view2 = view | std::views::filter([&min, p](auto &el){
        return !(min->second <= el.second && min->second + p > el.second);});
    j = 0;   
    for (auto &el : view2)
    {
        ++j;
        break;
    }
    if (j == 0)
        return 0;
    return 1;
}

int cover_cells(std::vector<std::pair<int, int>> &v, int w, int h, int p)
{
    
    auto &base = v.front();
    int j{};   

    if (vertical_first(base, v, p) == 0)
        return 0;

    int i = 0;
    int a{0};
    while (true)
    {
        auto view = v | std::views::filter([&base, i, p](auto &el){
            return !(base.second - i <= el.second && base.second - i + p > el.second);});
        j = 0;   
        for (auto &el : view)
        {
            ++j;
            break;
        }
        if (j == 0)
            return 0;
        auto &front = view.front();
        auto view2 = view | std::views::filter([&front, p](auto &el){
            return !(front.first <= el.first && front.first + p > el.first);});
        j = 0;   
        for (auto &el : view2)
        {
            ++j;
            break;
        }
        if (j == 0 || vertical_first(front, v, p) == 0)
            return 0;
        if (a >= front.first)
            break;
        a = front.first;
        i = base.second - front.second;
    }
    return 1;
}

int main(int argc, char const *argv[])
{
    int w, h, n, res{1};
    std::cin >> w >> h >> n;
    std::vector<std::pair<int, int>> v;
    v.reserve(n);
    int l{1}, r{std::min(w, h)};
    for (int i{}; i < n; ++i)
    {
        std::pair<int, int> p;
        std::cin >> p.first >> p.second;
        v.push_back(p);
    }
    std::ranges::sort(v);
    if (cover_cells(v, w, h, 1) != 0)
    {
        while (l < r-1)
        {
            if (cover_cells(v, w, h, l + (r-l)/2) == 0)
                r = l + (r-l)/2;
            else
                l += (r-l)/2;
        }
        std::cout << r << std::endl;
    }
    else
        std::cout << l << std::endl;
    return 0;
}


// #include <iostream>
// #include <vector>
// #include <ranges>
// #include <algorithm>
// #include <unordered_set>
// #include <limits>

// int cover_cells(std::vector<std::pair<int, int>> &v, int w, int h, int p, std::vector<std::pair<int, int>> &v2, std::vector<int> &v3)
// {
    
//     auto &base = v.front();

//     {
//         auto view = v | std::views::filter([&base, p](auto &el){
//             return !(base.first <= el.first && base.first + p > el.first);});
//         int j{};   
//         for (auto &el : view)
//         {
//             ++j;
//             break;
//         }
//         if (j == 0)
//             return 0;
//         auto min = std::ranges::min_element(view, [](auto &l, auto &r){return l.second < r.second;});
//         auto view2 = view | std::views::filter([&min, p](auto &el){
//             return !(min->second <= el.second && min->second + p > el.second);});
//         j = 0;   
//         for (auto &el : view2)
//         {
//             ++j;
//             break;
//         }
//         if (j == 0)
//             return 0;
//     }
//     auto view3 = v3 | std::views::filter([&base, p](auto &el){
//         return el - base.second < p && el - base.second >= 0;});
//     auto view4 = v2 | std::views::filter([&base, p](auto &el){
//         return !(el.second - base.second < p) || !(base.second - p < el.second);});
//     auto [min, max] = std::ranges::minmax_element(view4);
//     if (max->first - min->first >= p)
//         return 1;
//     for (auto &el : view3)
//     {
//         // std::cout << el << " " << base.second << " " << p << std::endl;
//         int i = base.second - el + p - 1;
//         auto view5 = v2 | std::views::filter([&base, p, i](auto &el){
//             return !(el.second - base.second + i < p) || !(base.second - i - p < el.second);});
//         auto [min1, max1] = std::ranges::minmax_element(view5);
//         if (max1->first - min1->first >= p)
//             return 1;
//         auto view = v | std::views::filter([&base, i, p](auto &el){
//             return !(base.second - i <= el.second && base.second - i + p > el.second);});
//         int j{};   
//         for (auto &el : view)
//         {
//             ++j;
//             break;
//         }
//         if (j == 0)
//             return 0;
//         auto &front = view.front();
//         auto view2 = view | std::views::filter([&front, p](auto &el){
//             return !(front.first <= el.first && front.first + p > el.first);});
//         j = 0;   
//         for (auto &el : view2)
//         {
//             ++j;
//             break;
//         }
//         if (j == 0)
//             return 0;
//     }
//     return 1;
// }

// int main(int argc, char const *argv[])
// {
//     int w, h, n, res{1};
//     std::cin >> w >> h >> n;
//     std::vector<std::pair<int, int>> v1;
//     std::vector<std::pair<int, int>> v2;
//     std::unordered_set<int> set;
//     std::vector<int> v3;
//     v1.reserve(n);
//     v2.reserve(n);
//     int l{1}, r{std::min(w, h)};
//     for (int i{}; i < n; ++i)
//     {
//         std::pair<int, int> p;
//         std::cin >> p.first >> p.second;
//         v1.push_back(p);
//         v2.push_back(p);
//         set.insert(p.second);
//     }
//     v3.assign(set.begin(), set.end());
//     std::ranges::sort(v3, std::greater<int>());
//     std::ranges::sort(v1);
//     std::ranges::sort(v2, [](auto &l, auto &r){
//         if (l.second != r.second)
//             return l.second > r.second;
//         else 
//             return l.first < r.first;});
//     if (cover_cells(v1, w, h, 1, v2, v3) != 0)
//     {
//         while (l < r-1)
//         {
//             if (cover_cells(v1, w, h, l + (r-l)/2, v2, v3) == 0)
//                 r = l + (r-l)/2;
//             else
//                 l += (r-l)/2;
//         }
//         std::cout << r << std::endl;
//     }
//     else
//         std::cout << l << std::endl;
//     return 0;
// }




        // auto view5 = v2 | std::views::filter([&base, p, i](auto &el){
        //     return !(el.second - base.second + i < p) || !(base.second - i - p < el.second);});
        // auto [min1, max1] = std::ranges::minmax_element(view5);
        // if (max1->first - min1->first >= p)
        //     return 1;
