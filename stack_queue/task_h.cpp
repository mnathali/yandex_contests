#include <iostream>
#include <vector>
#include <string>

int main(int argc, char const *argv[])
{
    int n;
    std::vector<int> v1;
    std::vector<long long> v2;
    std::cin >> n;
    v2.push_back(0);
    for (int i{}; i < n; ++i)
    {
        std::string s;
        std::cin >> s;
        if (s[0] == '+')
        {
            v1.push_back(std::stoi(s));
            v2.push_back(v2.back() + v1.back());
        }
        else if (s[0] == '-')
        {
            std::cout << v1.back() << std::endl;
            v1.pop_back();
            v2.pop_back();
        }
        else if (s[0] == '?')
        {
            std::cout << v2[v2.size() - 1] - v2[v2.size() - 1 - std::stoi(s.substr(1))] << std::endl;
        }
    }
    return 0;
}
