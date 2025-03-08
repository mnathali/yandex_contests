#include <iostream>
#include <ranges>
#include <set>
#include <algorithm>


int main(int argc, char const *argv[])
{
    int n;

    std::cin >> n;
    unsigned long long m = 0;
    for (int i = 0, j = 0, total = 0; total < n+1;++total)
    {
        unsigned long long sq = (unsigned long long)i * i;
        unsigned long long qr = (unsigned long long)j * j * j;
        m = sq < qr ? sq : qr;
        if (sq == qr)
        {
            ++i;
            ++j;
        }
        else if (sq > qr)
            ++j;
        else
            ++i;
        
    }
    std::cout << m << std::endl;
    return 0;
}
