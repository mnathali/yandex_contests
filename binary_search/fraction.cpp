#include <iostream>
#include <cmath>

int main(int argc, char const *argv[])
{
    long long n;

    std::cin >> n;

    long long pow = 1 + 8 * n;
    long long l{1}, r{6074000997};
    while (l < r-1)
    {
        if ((l + (r-l) / 2) * (l + (r-l) / 2) > pow)
            r = (l + (r-l) / 2);
        else
            l = (l + (r-l) / 2);
    }
    auto i = (-1 + std::sqrt((long double)(1 + 8 * n))) / 2;
    auto j = (l - 1) / 2;
    long long m = (j * (j + 1)) / 2;
    auto diagonal = j + ((l - 1) % 2 || pow - l * l ? 1 : 0);
    if (diagonal % 2)
        std::cout << (n == m ? diagonal : n - m) << "/" << (n == m ? 1 : diagonal - (n - m) + 1) << std::endl;
    else
        std::cout << (n == m ? 1 : diagonal - (n - m) + 1) << "/" << (n == m ? diagonal : n - m) << std::endl;
    return 0;
}

