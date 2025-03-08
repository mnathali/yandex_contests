#include <iostream>
#include <unordered_map>
#include <ranges>
#include <array>
#include <algorithm>

int main(int argc, char const *argv[])
{
    int N, year;
    std::array<unsigned, 7> week{0, 0, 0, 0, 0, 0, 0};
    std::unordered_map<std::string, unsigned> months;
    std::unordered_map<std::string, unsigned> week_days{{"Monday", 0}, {"Tuesday", 1},
    {"Wednesday", 2}, {"Thursday", 3}, {"Friday", 4}, {"Saturday", 5}, {"Sunday", 6}};
    std::unordered_map<unsigned, std::string> week_days_r{{0, "Monday"}, {1, "Tuesday"},
    {2, "Wednesday"}, {3, "Thursday"}, {4, "Friday"}, {5, "Saturday"}, {6, "Sunday"}};
    std::cin >> N >> year;
    for (auto &el : std::initializer_list<std::pair<std::string, unsigned>>
    {{"January", 0}, {"February", 31}, {"March", 59}, {"April", 90}, {"May", 120},
    {"June", 151}, {"July", 181}, {"August", 212}, {"September", 243}, {"October", 273},
    {"November", 304}, {"December", 334}})
        months[el.first] = el.second + (el.first != "January" && el.first != "February" && 
        (year % 400 == 0 || year % 4 == 0 && year % 100 != 0) ? 1 : 0);
    for (auto i: std::views::iota(0, N))
    {
        std::string month;
        int day;
        std::cin >> day >> month;
        week[(months[month] + day - 1) % 7] += 1;
    }
    std::string w_day;
    std::cin >> w_day;
    std::rotate(week.rbegin(), week.rbegin() + week_days[w_day], week.rend());
    for (int i{}; i < week_days[w_day]; ++i)
        ++week[i];
    for (unsigned i{(months["December"] + 31 - 1 + week_days[w_day]) % 7 + 1}; i < 7; ++i)
        ++week[i];
    // for (int i{}; i < 7; ++i)
    //     std::cout << i << " - " << week[i] << std::endl;
    auto min_max = std::minmax_element(week.begin(), week.end());
    std::cout << week_days_r[min_max.first - week.begin()] << " "
        << week_days_r[min_max.second - week.begin()] << std::endl;
    return 0;
}
