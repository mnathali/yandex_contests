#include <iostream>
#include <vector>

int main(int argc, char const *argv[])
{
    int n, m;
    long long sm{};
    std::vector<int> v;
    std::vector<long long> v_s;

    std::cin >> n >> m;
    v.resize(n);
    v_s.resize(n+1);
    for (int i{}; i < n; ++i)
    {
        std::cin >> v[i];
        sm += v[i];
        v_s[i+1] = sm;
    }
    for (int i{}; i < m; ++i)
    {
        long long l, s;
        int res{-1};
        std::cin >> l >> s;
        int a{}, b{n-1};
        if (a + l <= n && v_s[a + l] - v_s[a] <= s && v_s[b+1] - v_s[b+1 - l] >= s)
        {
            while (a < b-1 && a + (b - a) / 2 + l <= n && v_s[a + l] - v_s[a] < s)
            {

                if (v_s[a + (b - a) / 2 + l] - v_s[a + (b - a) / 2] > s)
                    b = a + (b - a) / 2;
                else
                    a += (b - a) / 2;
            }
            while (a + l <= n && v_s[a + l] - v_s[a] < s)
                ++a;
            if (a + l <= n && v_s[a + l] - v_s[a] == s)
                res = a + 1;
        }
        std::cout << res << std::endl;
    }
    return 0;
}
