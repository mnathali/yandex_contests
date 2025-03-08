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
    v[0].second = 1;
    for (int i = 0; i < s.size(); ++i)
    {
        v[i+1].first = (v[i].first * x + s[i]) % p;
        v[i+1].second = (v[i].second * x) % p;
    }
    std::cout << 0;
    for (int i = 1; i < s.size(); ++i)
    {
        int a = 0, b = i, l = b, r = b+1;
        if ((v[a + r-l].first + v[b].first * v[r-l].second) % p
            == (v[b + r-l].first + v[a].first * v[r-l].second) % p)
        {
            r = s.size();
            while (l < r - 1)
            {
                if ((v[a + (r-l)/2 + l - b].first + v[b].first * v[(r-l)/2 + l - b].second) % p
                    == (v[b + (r-l)/2 + l - b].first + v[a].first * v[(r-l)/2 + l - b].second) % p)
                    l += (r-l)/2;
                else
                    r = (r-l)/2 + l;
            }
            if (s[r - 1] == s[a + r - b - 1])
                l = r;
            std::cout << " " << l - b;
        }
        else
            std::cout << " " << 0;
    }
    std::cout << std::endl;
    return 0;
}
