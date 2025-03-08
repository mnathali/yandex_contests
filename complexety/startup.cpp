#include <iostream>
#include <string>

int main(int argc, char const *argv[])
{
    unsigned long n, k, d;

    std::cin >> n >> k >> d;

    std::string s("-1");

    for (int i{0}; i < 10; ++i)
        if ((10 * n + i) % k == 0)
        {
            s = std::to_string(10 * n + i);
            s += std::string(d - 1, '0');
            break;
        }
    std::cout << s << std::endl;
    return 0;
}
