#include <iostream>
#include <ranges>
#include <algorithm>

int main(int argc, char const *argv[])
{
    std::string desk;
    for (int i{}; i < 8; ++i)
    {
        std::string s;
        std::cin >> s;
        desk += s.substr(0, 8);
    }

    for (int i{}; i < desk.size(); ++i)
    {
        if (desk[i] == 'B')
        {
            for (int j{i - 9}; j >= 0 && j % 8 < i % 8 && desk[j] != 'R' && desk[j] != 'B'; j -= 9)
                desk[j] = '0';
            for (int j{i + 9}; j < desk.size() && j % 8 > i % 8 && desk[j] != 'R' && desk[j] != 'B'; j += 9)
                desk[j] = '0';
            for (int j{i - 7}; j >= 0 && j % 8 > i % 8 && desk[j] != 'R' && desk[j] != 'B'; j -= 7)
                desk[j] = '0';
            for (int j{i + 7}; j < desk.size() && j % 8 < i % 8 && desk[j] != 'R' && desk[j] != 'B'; j += 7)
                desk[j] = '0';
        }
        else if (desk[i] == 'R')
        {
            for (int j{i + 1}; j < desk.size() && j % 8 > i % 8 && desk[j] != 'R' && desk[j] != 'B'; ++j)
                desk[j] = '0';
            for (int j{i - 1}; j >= 0 && j % 8 < i % 8 && desk[j] != 'R' && desk[j] != 'B'; --j)
                desk[j] = '0';
            for (int j{i + 8}; j < desk.size() && desk[j] != 'R' && desk[j] != 'B'; j += 8)
                desk[j] = '0';
            for (int j{i - 8}; j >= 0 && desk[j] != 'R' && desk[j] != 'B'; j -= 8)
                desk[j] = '0';
        }
    }
    // for (int i{}; i < 8; ++i)
    //     std::cout << desk.substr(8 * i, 8) << std::endl;
    std::cout << std::count(desk.begin(), desk.end(), '*') << std::endl;
    return 0;
}

