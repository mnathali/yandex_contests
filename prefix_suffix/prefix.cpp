#include <iostream>

int main(int argc, char const *argv[])
{
    int n{}, val{};

    std::cin >> n;
    
    for (int i{}, sum{}; i < n; ++i)
    {
        std::cin >> val;
        sum += val;
        std::cout << sum << " ";
    }
    std::cout << std::endl;
    return 0;
}
