#include <iostream>
#include <map>

int main(int argc, char const *argv[])
{
    int n, r, count{};
    std::cin >> n >> r;
    std::map<int, int> mp;

    for (int i{}; i < n; ++i)
    {
        int val;
        std::cin >> val;
        auto indicator = mp.insert(mp.cend(), {val, i+1});
        auto up = mp.lower_bound(val - r);
        if (up != mp.end() && up != mp.begin())
            count += (--up)->second;
    }
    std::cout << count << std::endl;
    return 0;
}
