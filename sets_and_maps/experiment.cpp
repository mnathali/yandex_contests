#include <iostream>
#include <unordered_map>

int main(int argc, char const *argv[])
{
    int n, k;
    std::unordered_map<int, int> mp;
    std::cin >> n >> k;

    for (int i{}; i < n; ++i)
    {
        int a;
        std::cin >> a;
        if (mp[a] != 0 && i - mp[a] <= k){
            std::cout << "YES" << std::endl;
            return 0;
        }
        mp[a] = i;
    }
    std::cout << "NO" << std::endl;
    return 0;
}
