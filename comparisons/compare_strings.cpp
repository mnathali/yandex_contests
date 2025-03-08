#include <iostream>
#include <vector>
#include <ranges>

int main(int argc, char const *argv[])
{
    std::string s;
    int q;
    unsigned p = 1000000007;
    unsigned x = 257;

    std::cin >> s;
    std::cin >> q;
    std::vector<std::pair<unsigned long, unsigned long>> v(s.size() + 1);
    v[0].first = 0;
    v[0].second = 1;
    for (int i = 0; i < s.size(); ++i)
    {
        v[i+1].first = (v[i].first * x + s[i]) % p;
        v[i+1].second = (v[i].second * x) % p;
    }
    

    for (auto _ : std::views::iota(0, q))
    {
        int a, b, l;
        std::cin >> l >> a >> b;
        if ((v[a + l].first + v[b].first * v[l].second) % p
            == (v[b + l].first + v[a].first * v[l].second) % p)
            std::cout << "yes";
        else
            std::cout << "no";
        std::cout << std::endl;
    }
    return 0;
}
