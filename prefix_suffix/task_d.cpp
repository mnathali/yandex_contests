#include <iostream>
#include <map>

int main(int argc, char const *argv[])
{
    int n, k, counter{};
    std::map<int, int> mp;
    std::cin >> n >> k;

    for (int i{}; i < n; ++i)
    {
        int el;
        std::cin >> el;
        mp[el] += 1;
    }
    
    while (!mp.empty())
    {
        for (auto it = mp.begin(); it != mp.end();)
        {
            auto ite = mp.upper_bound(it->first + k);
            if (it->second == 1)
                mp.erase(it);
            else
                --(it->second);
            it = ite;
        }
        ++counter;
    }
    std::cout << counter << std::endl;
    return 0;
}
