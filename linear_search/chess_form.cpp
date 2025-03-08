#include <iostream>
#include <array>
#include <ranges>

int main(int argc, char const *argv[])
{
    int n, p{};
    std::array<std::array<int, 8>, 8> desk{};

    std::cin >> n;
    for (auto _ : std::views::iota(0, n))
    {
        int i, j;
        std::cin >> i >> j;
        p += 4;
        if (i > 1 && desk[i-1 - 1][j-1] == 1)
            p -= 2;
        if (i < 8 && desk[i-1 + 1][j-1] == 1)
            p -= 2;
        if (j > 1 && desk[i-1][j-1 - 1] == 1)
            p -= 2;
        if (j < 8 && desk[i-1][j-1 + 1] == 1)
            p -= 2;
        desk[i-1][j-1] = 1;
    }
    std::cout << p << std::endl;
    return 0;
}
