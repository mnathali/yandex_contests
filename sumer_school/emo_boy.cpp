#include <iostream>

int main(int argc, char const *argv[])
{
    
    std::string s;
    int lower{}, upper{}, number{};
    
    std::cin >> s;
    for (auto c : s)
    {
        if (c >= '0' && c <= '9')
            ++number;
        else if (c >= 'A' && c <= 'Z')
            ++upper;
        else if (c >= 'a' && c <= 'z')
            ++lower;
    }

    if (!lower || !upper || !number || s.size() < 8)
        std::cout << "NO" << std::endl;
    else
        std::cout << "YES" << std::endl;

    return 0;
}
