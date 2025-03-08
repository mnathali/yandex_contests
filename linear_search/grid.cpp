#include <iostream>
#include <ranges>
#include <limits>

int main(int argc, char const *argv[])
{
    int n, x1{std::numeric_limits<int>::max()},
            x2{std::numeric_limits<int>::min()},
            y1{std::numeric_limits<int>::max()},
            y2{std::numeric_limits<int>::min()};
            
    std::cin >> n;

    for (auto i: std::views::iota(0, n))
    {
        int x, y;
        std::cin >> x >> y;
        x1 = x1 < x ? x1 : x;
        y1 = y1 < y ? y1 : y;
        x2 = x2 > x ? x2 : x;
        y2 = y2 > y ? y2 : y;
    }
    std::cout << x1 << " " << y1 << " " << x2 << " " << y2 << std::endl;
    return 0;
}
