#include <iostream>
#include <vector>
#include <ranges>

int draw_rect(std::vector<std::string> &v, char c)
{
    for (int i{}; i < v.size(); ++i)
        for (int j{}; j < v[i].size(); ++j)
            if (v[i][j] == '#')
            {
                int sz{}, status{1}, j_start{j}, s_line{static_cast<int>(v[i].size()-j)};
                while (status == 1)
                {
                    while (j - j_start < s_line && v[i][j] == '#')
                    {
                        v[i][j] = c;
                        if (status && (i+1 >= v.size() || v[i+1][j] != '#'))
                            status = 0;
                        ++j;
                    }
                    if (i+1 < v.size() && j_start-1 >= 0 && j < v[i].size()
                        && v[i+1][j_start-1] == '#' && v[i+1][j] == '#')
                            status = 0;
                    s_line = j - j_start;
                    sz += j - j_start;
                    j = j_start;
                    ++i;
                }
                return sz;
            }
    return 0;
}

int main(int argc, char const *argv[])
{
    int m, n, total{};
    std::vector<std::string> v;
    std::cin >> m >> n;
    v.resize(m);
    for (auto i : std::views::iota(0, m))
    {
        v[i].resize(n);
        for (int j{}; j < n; ++j)
        {
            std::cin >> v[i][j];
            if (v[i][j] == '#')
                ++total;
        }
    }
    auto a = draw_rect(v, 'a');
    auto b = draw_rect(v, 'b');
    if (a + b < total || !(total > 1))
    {
        std::cout << "NO" << std::endl;
        return 0;
    }
    if (b == 0)
    {
        for (int i{}; i < m; ++i)
            for (int j{}; j < n; ++j)
                if (v[i][j] == 'a')
                {
                    if (j+1 < v[i].size() && v[i][j+1] == 'a')
                        for (;i < v.size() && v[i][j] == 'a'; ++i)
                            v[i][j] = 'b';
                    else
                        for (;j < v[i].size() && v[i][j] == 'a'; ++j)
                            v[i][j] = 'b';
                    i = v.size();
                    break;
                }
    }
    std::cout << "YES" <<std::endl;
    for (auto &line : v)
    {
        for (auto &el : line)
            std::cout << el;
        std::cout << std::endl;
    }

    return 0;
}
