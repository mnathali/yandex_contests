#include <iostream>
#include <vector>

int main(int argc, char const *argv[])
{

    std::string s;
    unsigned p = 1000000007;
    unsigned x = 257;

    std::cin >> s;
    std::vector<std::pair<unsigned long, unsigned long>> v(s.size() + 1);
    v[0].first = 0;
    v[0].second = 1;1
    for (int i = 0; i < s.size(); ++i)
    {
        v[i+1].first = (v[i].first * x + s[i]) % p;
        v[i+1].second = (v[i].second * x) % p;
    }
    int min = 1;
    for (;min < s.size();)
    {
        int a = 0, b = 0 + min, l = s.size() - min;

        if ((v[a + l].first + v[b].first * v[l].second) % p
            == (v[b + l].first + v[a].first * v[l].second) % p)
            break;
        ++min;
    }
    std::cout << min << std::endl;
    return 0;
}
