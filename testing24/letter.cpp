#include <iostream>
#include <vector>
#include <algorithm>
#include <ranges>

template<typename T>
std::ostream& operator<<(std::ostream& o, const std::vector<T>& vec)
{
    for (typename std::vector<T>::const_iterator it = vec.begin(); it < vec.end(); ++it)
        o << *it << std::endl;
    return o;
}

int main(int argc, char const *argv[])
{
    int n;
    std::cin >> n;
    int min_x{n}, max_x{}, min_y{n}, max_y{};
    std::vector<std::string> map = std::vector<std::string>();
    for (auto i: std::views::iota(0, n))
    {
        std::string s;
        std::cin >> s;
        if (auto first = s.find('#'), last = s.find_last_of('#'); first != std::string::npos)
        {
            if (first < min_x)
                min_x = first;
            if (last > max_x)
                max_x = last;
            if (map.size() < min_y)
                min_y = map.size();
            if (map.size() > max_y)
                max_y = map.size();
        }
        map.push_back(s);
    }
    auto letter = std::vector<std::string>();
    if (max_y < min_y || min_x > max_x)
    {
        std::cout << 'X' << std::endl;
        return 0;
    }
    for (int i{}; i < map.size(); ++i)
    {
        if (i >= min_y && i <= max_y)
            letter.push_back(map[i].substr(min_x, max_x - min_x + 1));
    }
    std::cout << letter << std::endl;
    std::vector<bool> x, y;
    for (int i = 0, len = std::count(letter.front().begin(), letter.front().end(), '#'); i < letter.size(); ++i)
    {
        auto tmp_len = std::count(letter[i].begin(), letter[i].end(), '#');
        if (len < tmp_len)
            y.insert(y.end(), {0, 1});
        else if (len > tmp_len)
            y.insert(y.end(), {1, 0});
        len = tmp_len;
    }
    for (int j = 0, len = std::count_if(letter.begin(), letter.end(), [](auto line){return line[0] == '#';}); j < letter.front().size(); ++j)
    {
        auto tmp_len = std::count_if(letter.begin(), letter.end(), [j](auto line){return line[j] == '#';});
        if (len < tmp_len)
            x.insert(x.end(), {0, 1});
        else if (len > tmp_len)
            x.insert(x.end(), {1, 0});
        len = tmp_len;
    }
    x.erase(std::unique(x.begin(), x.end()), x.end());
    y.erase(std::unique(y.begin(), y.end()), y.end());
    std::cout << x << std::endl << y;
    if (y.size() == 3 && std::equal(y.begin(), y.end(), std::begin({1, 0, 1})))
    {
        if (letter.back().size() != std::count(letter.back().begin(), letter.back().end(), '#')
            || letter.size() != std::count_if(letter.begin(), letter.end(), [](auto line){return line[0] == '#';})
            || letter.front().size() != std::count(letter.front().begin(), letter.front().end(), '#'))
            std::cout << 'X' << std::endl;
        else if (x.size() == 3 && std::equal(x.begin(), x.end(), std::begin({1, 0, 1})))
            std::cout << 'O' << std::endl;
        else if (x.size() == 2 && std::equal(x.begin(), x.end(), std::begin({1, 0})))
            std::cout << 'C' << std::endl;
    }
    else if (y.size() == 2 && x.size() == 2 && std::equal(y.begin(), y.end(), std::begin({0, 1})) && std::equal(x.begin(), x.end(), std::begin({1, 0})))
        std::cout << 'L' << std::endl;
    else if (y.empty() && x.empty())
    {
        if (letter.back().size() != std::count(letter.back().begin(), letter.back().end(), '#')
            || letter.size() != std::count_if(letter.begin(), letter.end(), [](auto line){return line[0] == '#';})
            || letter.front().size() != std::count(letter.front().begin(), letter.front().end(), '#'))
            std::cout << 'X' << std::endl;
        else
            std::cout << 'I' << std::endl;
    }
    else if (y.size() == 3 && x.size() == 3 && std::equal(y.begin(), y.end(), std::begin({0, 1, 0})) && std::equal(x.begin(), x.end(), std::begin({1, 0, 1})))
    {
        for (auto line: letter)
        {
            if (std::count(line.begin(), line.end(), '#') == line.size())
            {
                std::cout << 'H' << std::endl;
                return 0;
            }
        }
        std::cout << 'X' << std::endl;
    }
    else if (y.size() == 4 && x.size() == 3 && std::equal(y.begin(), y.end(), std::begin({1, 0, 1, 0})) && std::equal(x.begin(), x.end(), std::begin({1, 0, 1})))
    {
        if (letter.front().size() == std::count(letter.front().begin(), letter.front().end(), '#')
        && letter.size() == std::count_if(letter.begin(), letter.end(), [](auto line){return line[0] == '#';})
        && letter.back().back() == '.')
            std::cout << 'P' << std::endl;
        else
            std::cout << 'X' << std::endl;
    }
    else
        std::cout << 'X' << std::endl;
    return 0;
}
