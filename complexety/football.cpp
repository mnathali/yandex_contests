#include <iostream>
#include <ranges>
#include <string>
#include <vector>

int main(int argc, char const *argv[])
{
    std::string s1, s2;
    int i;
    std::cin >> s1 >> s2 >> i;

    auto scores_1 = s1 | std::views::split(':') | std::ranges::views::transform([](auto &&rng) {
        return std::stol(std::string(rng.begin(), rng.end()));});
    auto scores_2 = s2 | std::views::split(':') | std::ranges::views::transform([](auto &&rng) {
        return std::stol(std::string(rng.begin(), rng.end()));});
    std::vector scrs_1(scores_1.begin(), scores_1.end());
    std::vector scrs_2(scores_2.begin(), scores_2.end());

    if (scrs_1[0] + scrs_2[0] > scrs_1[1] + scrs_2[1])
        std::cout << 0 << std::endl;
    else if (scrs_1[0] + scrs_2[0] == scrs_1[1] + scrs_2[1])
        std::cout << (scrs_2[0] > scrs_1[1] && i == 1
        || scrs_1[0] > scrs_2[1] && i == 2 ? 0 : 1) << std::endl;
    else
        std::cout << (i == 1 && scrs_1[1] + scrs_2[1] - scrs_1[0] > scrs_1[1] ||
                    i == 2 && scrs_1[0] > scrs_2[1] ? 
            scrs_1[1] + scrs_2[1] - (scrs_1[0] + scrs_2[0]) : 
            scrs_1[1] + scrs_2[1] - (scrs_1[0] + scrs_2[0]) + 1) << std::endl;

    return 0;
}
