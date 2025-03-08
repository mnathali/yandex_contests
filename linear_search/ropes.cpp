#include <iostream>
#include <ranges>

int main(int argc, char const *argv[])
{
    int n, sum{}, max{};

    std::cin >> n;
    
    for (auto _ : std::views::iota(0, n))
    {
        int m;
        std::cin >> m;

        sum += m;
        max = m > max ? m : max;
    }
    std::cout << (max - (sum - max) > 0 ? max - (sum - max) : sum) << std::endl;
    return 0;
}
