#include <iostream>
#include <algorithm>
#include <vector>

template<typename T, typename V>
std::ostream& operator<<(std::ostream& o, const std::pair<T, V>& pair)
{
    o << '{' << pair.first << ", " << pair.second << "}";
    return o;
}

template<typename T>
std::ostream& operator<<(std::ostream& o, const std::vector<T>& vec)
{
    o << '[';
    for (typename std::vector<T>::const_iterator it = vec.begin(); it < vec.end(); ++it)
        o << *it << ",";
    o << ']';
    return o;
}

int check_point(std::vector<std::string> &map, std::pair<int, int> base, int max, int n, int m)
{   
    
    auto status = base.first - max - 1 < 0 || base.first + 2 * max >= n || base.second - max - 1 < 0 || base.second + 2 * max >= m
        || base.first - max - 1 >= 0 && map[base.first - max - 1][base.second] != '#'
        || base.first - max - 1 >= 0 && base.second + max < m && map[base.first - max - 1][base.second + max] != '#'
        || base.second - max - 1 >= 0 && map[base.first][base.second - max - 1] != '#'
        || base.second + max < m && map[base.first][base.second + max] != '#'
        || base.second + 2 * max < m && map[base.first][base.second + 2 * max] != '#'
        || base.second - max - 1 >= 0 && base.first + max < n && map[base.first + max][base.second - max - 1] != '#'
        || base.first + max < n && map[base.first + max][base.second] != '#'
        || base.second + max < m && base.first + max < n && map[base.first + max][base.second + max] != '#'
        || base.second + 2 * max < m && base.first + max < n && map[base.first + max][base.second + 2 * max] != '#'
        || base.first + 2 * max < n && map[base.first + 2 * max][base.second] != '#'
        || base.second + max < m && base.first + 2 * max < n && map[base.first + 2 * max][base.second + max] != '#';

    if (status)
        return status;
    for (int i{}; base.first - max - 1 >= 0 && base.second + i < m && i < max + 1; ++i)
        if (map[base.first - max - 1][base.second + i] != '#')
            return 1;
    for (int i{}; base.first - max - 1 >=0 && base.second + max < m && i < max + 1; ++i)
        if (map[base.first - max - 1 + i][base.second + max] != '#')
            return 1;
    for (int i{}; base.first + i < n && base.second + 2 * max < m && i < max + 1; ++i)
        if (map[base.first + i][base.second + 2 * max] != '#')
            return 1;
    for (int i{}; base.first + max < n && base.second + max + i < m && i < max; ++i)
        if (map[base.first + max][base.second + max + i] != '#')
            return 1;
    for (int i{}; base.first + max + i < n && base.second + max < m && i < max + 1; ++i)
        if (map[base.first + max + i][base.second + max] != '#')
            return 1;

    return status;
}

int is_plus_curr_size(int k, std::pair<int, int> base, std::vector<std::string> &map,
    std::vector<int> &mins_h, std::vector<int> &mins_v, std::vector<int> &maxs_h, std::vector<int> &maxs_v)
{
    for (int i{1}; i < k; ++i)
        if (mins_h[(base.first + i) * map[0].size() + base.second] - 1 < k)
            return 0;
    for (int i{1}; i < k; ++i)
        if (maxs_h[(base.first + i) * map[0].size() + base.second] - 1 < k)
            return 0;
    for (int i{1}; i < k; ++i)
        if (mins_v[base.first * map[0].size() + base.second + i] - 1 < k)
            return 0;
    for (int i{0}; i < k; ++i)
        if (maxs_h[(base.first + i) * map[0].size() + base.second + k - 1] - 1 < k)
            return 0;
    for (int i{0}; i < k; ++i)
        if (maxs_v[(base.first + k - 1) * map[0].size() + base.second + i] - 1 < k)
            return 0;
    return 1;
}

int get_max_plus(std::pair<int, int> base, int r, std::vector<std::string> &map, std::vector<int> &sizes,
    std::vector<int> &mins_h, std::vector<int> &mins_v, std::vector<int> &maxs_h, std::vector<int> &maxs_v)
{
    int shift = 0;
    if (sizes[base.first * map[0].size() + base.second - 1])
        shift = sizes[base.first * map[0].size() + base.second - 1] - 1;
    else if (sizes[(base.first - 1) * map[0].size() + base.second])
        shift = sizes[(base.first - 1) * map[0].size() + base.second] - 1;
    int l{shift + 1};
    if (is_plus_curr_size(r, base, map, mins_h, mins_v, maxs_h, maxs_v) == 1)
        return r;
    if (is_plus_curr_size(l, base, map, mins_h, mins_v, maxs_h, maxs_v) == 0)
        return l;
    while (l < r-1)
    {
        if (is_plus_curr_size(l + (r - l) / 2, base, map, mins_h, mins_v, maxs_h, maxs_v) == 0)
            r = l + (r - l) / 2;
        else
            l += (r - l) / 2;
    }
    return l;
}

int main(int argc, char const *argv[])
{
    int n, m, max{1};
    std::vector<std::pair<int, int>> v;
    std::vector<std::string> map;
    std::vector<int> sizes;
    std::vector<int> mins_h;
    std::vector<int> mins_v;
    std::vector<int> maxs_h;
    std::vector<int> maxs_v;

    std::cin >> n >> m;
    sizes.resize(n * m);
    mins_h.resize(n * m);
    mins_v.resize(n * m);
    maxs_h.resize(n * m);
    maxs_v.resize(n * m);
    map.resize(n, std::string());
    int min_l{m-1}, max_r{0}, max_d{0}, min_h{n-1};
    for (int i{}; i < n; ++i)
    {
        map[i].resize(m);
        for (int j{}; j < m; ++j)
        {
            std::cin >> map[i][j];
            if (map[i][j] == '#')
            {
                v.push_back({i, j});
                if (j < min_l)
                    min_l = j;
                if (j > max_r)
                    max_r = j;
                if (i > max_d)
                    max_d = i;
                if (i < min_h)
                    min_h = i;
                mins_h[i * m + j] = (j == 0 ? 1 : (mins_h[i * m + j - 1] + 1));
                mins_v[i * m + j] = (i == 0 ? 1 : (mins_v[(i - 1) * m + j] + 1));
            }
        }
    }
    for (int i{}; i < n; ++i)
        for (int j{}; j < m; ++j)
            if (map[n - 1 - i][m - 1 - j] == '#')
            {
                maxs_h[(n - 1 - i) * m + m - 1 - j] = (j == 0 ? 1 : (maxs_h[(n - 1 - i) * m + m - 1 - j + 1] + 1));
                maxs_v[(n - 1 - i) * m + m - 1 - j] = (i == 0 ? 1 : (maxs_v[(n - 1 - i + 1) * m + m - 1 - j] + 1));
            }
    for (int i{}; i < v.size(); ++i)
    {
        if (v.size() - i < max * max * 3)
            break;
        int r{std::min({mins_h[v[i].first * m + v[i].second] - 1, mins_v[v[i].first * m + v[i].second] - 1, maxs_h[v[i].first * m + v[i].second] / 2, maxs_v[v[i].first * m + v[i].second] / 2})};
        if (r <= max || check_point(map, v[i], max, n, m))
            continue;
        auto tmp_max = get_max_plus(v[i], r, map, sizes, mins_h, mins_v, maxs_h, maxs_v);
        sizes[v[i].first * m + v[i].second] = tmp_max;
        if (tmp_max > max)
            max = tmp_max;
        // std::cout << i << " " << max << std::endl;
    }
    std::cout << max << std::endl;
    return 0;
}



