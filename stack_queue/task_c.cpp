#include <iostream>
#include <map>
#include <vector>

int main(int argc, char const *argv[])
{
    int n, k;
    std::vector<int> v;
    std::map<int, int> mp;
    std::cin >> n >> k;
    v.reserve(n);

    for (int i{}; i < n; ++i)
    {
        int val;
        std::cin >> val;
        v.push_back(val);
    }
    for (int i{}; i < k; ++i)
        mp[v[i]] += 1;
    std::cout << mp.begin()->first << std::endl;
    for (int i = 0; i + k < n; ++i)
    {
        auto it = mp.find(v[i]);
        if ((--it->second) == 0)
            mp.erase(it);
        mp[v[i+k]] += 1;
        std::cout << mp.begin()->first << std::endl;
    }
    return 0;
}
