#include <iostream>

int main(int argc, char const *argv[])
{
    int k{1};
    long long n, s{0};
    std::cin >> n;

    for (long long i{0}, p{0}, m{1}; true; ++k, ++m)
    {
        // std::cout << s << " " << i << " " << p << " " << m << std::endl;
        if (s + k + i + p + m - 1 > n)
            break;
        s += k + i;
        i += k;
        p += m;
    }
    std::cout << k-1 <<std::endl;
    return 0;
}
