#include <iostream>
#include <string>
#include <stack>
#include <ctype.h>
#include <stdlib.h>
int recursive_calc(std::string &s, int &i);

int multi(std::string &s, int &i)
{
    int reduce{};
    if (s[i] == '(')
    {
        ++i;
        reduce = recursive_calc(s, i);
    }
    else
    {
        reduce = atoi(s.data() + i);
        i = s.find_first_not_of("0123456789", i+1);
    }

    while (s[i] == '*')
    {
        ++i;
        if (s[i] == '(')
            reduce *= recursive_calc(s, ++i);
        else
        {
            reduce *= atoi(s.data() + i);
            i = s.find_first_not_of("0123456789", i);
        }
    }
    return reduce;
}

int recursive_calc(std::string &s, int &i)
{
    int reduce{};
    reduce = multi(s, i);

    while (s[i] != ')')
    {
        if (s[i] == '-')
            reduce -= multi(s, ++i);
        else
            reduce += multi(s, ++i);
    }
    ++i;
    return reduce;
    
}

int main(int argc, char const *argv[])
{
    std::string s;
    int n{0};
    
    std::getline(std::cin, s);

    auto index = s.find_first_not_of(' ');
    if (index != std::string::npos)
        s.erase(s.begin(), s.begin() + index);
    index = s.find_last_not_of(' ');
    if (index != std::string::npos)
        s.erase(s.begin() + index + 1, s.end());
    for (int i{}; i < s.size(); ++i)
    {
        if (s[i] == ' ')
        {
            index = s.find_first_not_of(' ', i);
            if (isdigit(s[index]) && isdigit(s[i-1])
            || !isdigit(s[index]) && std::string("+*-()").find(s[index]) == std::string::npos
            || !isdigit(s[i-1]) && std::string("+*-()").find(s[i-1]) == std::string::npos)
            {
                std::cout << "WRONG" << std::endl;
                return 0;
            }
            s.erase(s.begin() + i, s.begin() + index);
            --i;
        }
        else if (!isdigit(s[i]) && std::string("+*-()").find(s[i]) == std::string::npos
        || (i + 1) < s.size() && std::string("+*-").find(s[i]) != std::string::npos && std::string("+*-").find(s[i+1]) != std::string::npos
        || (i + 1) < s.size() && std::string("(").find(s[i]) != std::string::npos && std::string("+*").find(s[i+1]) != std::string::npos)
        {
            std::cout << "WRONG" << std::endl;
            return 0;
        }
        else if (s[i] == '(')
            ++n;
        else if (s[i] == ')')
            --n;
        if (n < 0)
        {
            std::cout << "WRONG" << std::endl;
            return 0;
        }
    }
    if (n != 0 || s.empty() || std::string("+*").find(s[0]) != std::string::npos
    || std::string("+*-").find(s[s.size() - 1]) != std::string::npos)
    {
        std::cout << "WRONG" << std::endl;
        return 0;
    }
    s = "(" + s + ")";
    int i = 1;
    std::cout << recursive_calc(s, i) << std::endl;

    return 0;
}
