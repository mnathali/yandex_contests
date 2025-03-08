#include <iostream>
#include <vector>
using hash_type = std::vector<std::pair<unsigned long, unsigned long>>;

int binary_search_palindrom(int i, int j, hash_type &v, hash_type &v_reverse, unsigned p)
{
    int cnt = j - i, size = v.size() - 1;
    int r = size - j - 1 > i ? i : size - j - 1;
    if (!r || (v[j+1].first + v_reverse[size - j - 2].first * v_reverse[j - i + 2].second) % p
            != (v_reverse[size - i].first + v[i-1].first * v[j - i + 2].second) % p)
    {

    std::cout << cnt << " " << i << "-" << j << std::endl;
        return cnt;
    }
    while ((v[j+r].first + v_reverse[size - j - r - 1].first * v_reverse[j - i + 2 * r].second) % p
            != (v_reverse[size - i + r - 1].first + v[i-r].first * v[j - i + 2 * r].second) % p)
        --r;
    cnt += r;
    std::cout << cnt << " " << i << "-" << j << std::endl;
    return cnt;
}



int main(int argc, char const *argv[])
{
    unsigned p = 1000000007;
    unsigned x = 257;
    std::string s;
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
    std::size_t cnt{s.size()};
    for (int i = 0; i < s.size() - 1; ++i)
    {
        cnt += binary_search_palindrom(i, i, v, v_reverse, p);
        if (s[i] == s[i+1])
            cnt += binary_search_palindrom(i, i+1, v, v_reverse, p);
    }
    std::cout << cnt << std::endl;
    return 0;
}
