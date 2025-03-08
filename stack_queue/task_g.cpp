#include <iostream>

int main(int argc, char const *argv[])
{
    int n, b;
    unsigned long long k{}, m{};

    std::cin >> n >> b;

    for (int i{}; i < n; ++i)
    {
        int val;
        std::cin >> val;
        k += val;
        m += k;
        k -= b > k ? k : b;
    }
    m += k;
    std::cout << m << std::endl;
    return 0;
}
