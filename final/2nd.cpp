#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>

int main(int argc, char const *argv[])
{
    unsigned p = 1000000007;
    unsigned x = 257;
    int n;
    std::string s;
    std::cin >> n;
    s.reserve(n);
    std::cin >> s;
    std::vector<std::pair<unsigned long, unsigned long>> v(s.size() + 1);
    std::vector<std::pair<unsigned long, unsigned long>> v_reverse(s.size() + 1);
    v[0].first = 0;
    v[0].second = 1;
    v_reverse[0].first = 0;
    v_reverse[0].second = 1;
    for (int i = 0; i < s.size(); ++i)
    {
        v[i+1].first = (v[i].first * x + s[i]) % p;
        v[i+1].second = (v[i].second * x) % p;
        v_reverse[i+1].first = (v_reverse[i].first * x + s[s.size() - 1 - i]) % p;
        v_reverse[i+1].second = (v_reverse[i].second * x) % p;
    }

    for (int i = 1; i <= s.size(); ++i)
    {
        int a = 0, size = s.size(), l = 1, r = i;
        if ((v[a + 1].first + v_reverse[size - i].first * v_reverse[1].second) % p
            == (v_reverse[size - i + 1].first + v[a].first * v[1].second) % p)
        {
            while (l < r-1)
            {
                if ((v[a + l + (r-l)/2].first + v_reverse[size - i].first * v_reverse[l+(r-l)/2].second) % p
                == (v_reverse[size - i + l + (r-l)/2].first + v[a].first * v[l+(r-l)/2].second) % p)
                    l += (r-l)/2;
                else
                    r = l + (r-l)/2;
            }
            std::cout << l << " ";
        }
        else
            std::cout << 0 << " ";
    }
    std::cout << std::endl;
    return 0;
}