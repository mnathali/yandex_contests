#include <iostream>
#include <limits>

int defeat_base(int x, int P)
{
    int i{0};
    for (; x > 0 && P > 0; ++i)
    {
        // std::cout << x << " " << P << std::endl;
        P -= x;
        x -= P > 0 ? P : 0;
    }
    if (x <= 0)
        return -1;
    return i;
}

int main(int argc, char const *argv[])
{
    int x, y, p, i{1}, P{}, min(std::numeric_limits<int>::max());

    std::cin >> x >> y >> p;

    y -= x;
    if (y > 0)
        P = p;
    if (x == y && y == p )
        x = 0;
    for (; min > i && x > 0 && (P > 0 || y > 0); ++i)
    {
        // std::cout << x << " " << y << " " << P << " -->" << i << std::endl;
        int j;
        if (x > y && y + P > x &&
            (j = defeat_base((x - y > P ? x : x - (P - (x - y))), (x - y > P ? 0 : P - (x - y)))) > 0)
        {
            // std::cout << j << std::endl;
            if (i + j + 1 < min)
                min = i + j + 1;
            // std::cout << i + j + 1 << " " << i << std::endl;
        }
        if (y > 0 && (x > P ? x - P : 0) == 0)
        {
            x = 0;
            break;
        }
        auto left = x > P ? 0 : P - x;
        y -= (x > P ? x - P : 0);
        P = (x > P ? 0 : P - x) + (y > 0 ? p : 0);
        x -= left;
    }
    if (x <= 0 && min == std::numeric_limits<int>::max())
        std::cout << -1 << std::endl;
    else if (x <= 0)
        std::cout << min << std::endl;
    else
        std::cout << (min < i ? min : i) << std::endl;
    return 0;
}

// (x - (p + n * p) - y) / y = n


        // int max{std::numeric_limits<int>::min()};
        // int j{}, k{};
        // std::cout << x << " " << y << " " << P << std::endl;
        // for (; j <= x && j <= P; ++j)
        // {
        //     // std::cout << j << " " << x - (P - j) - (P - j + (y > x - j ? p : 0)) << std::endl;
        //     if (x - (P - j) - (P - j + (y > x - j ? p : 0)) > max)
        //     {
        //         max = x - (P - j) - (P - j + (y > x - j ? p : 0));
        //         k = j;
        //     }
        // }
        // if (x > y && P - (x - y) <= x - (P - (x - y)))
        //     k = x - y;
        // std::cout << k << std::endl;
        // y -= x - k;
        // x = P - k > x ? 0 : x - (P - k);
        // P = P - k + (y > 0 ? p : 0);

        // int a = (x >= y ? 0 : p) + (x >= y ? (P > x - y ? P - (x - y) : 0) : P);
        // int b = (x > P ? 0 : P - x) + (x > P ? (x - P >= y ? 0 : p) : (y > 0 ? p : 0));
        // std::cout << x << " " << y << " " << a << " " << b << " " << P << std::endl;
        // if ( a - (x > y ? (x - y > P ? x : x - (P - (x - y))) : (P > x ? 0 : x - P))
        //         < b - (x > P ? x : (P - x) > x ? 0 : x - (P - x)) )
        // {
        //     auto left = x > y ? x - y : 0;
        //     y = x > y ? 0 : y - x;
        //     x = left > P ? x : (P - left > x ? 0 : x - P + left);
        //     P = a;
        // }
        // else
        // {
        //     y = x > P ? (y > x - P ? y - x + P : 0): y;
        //     x = x > P ? x : (x > P - x ? x - (P - x) : 0);
        //     P = b;
        // }
