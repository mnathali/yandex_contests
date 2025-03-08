#include <iostream>
#include <string>
#include <stack>
#include <ctype.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    std::string s;
    std::stack<int> stk;

    std::getline(std::cin, s);
    std::cout << s << std::endl;
    for (std::size_t i{}; i < s.size(); ++i)
    {
        if (s[i] == ' ')
            continue;
        if (isdigit(s[i]))
        {
            stk.push(atoi(s.data() + i));
            i = s.find_first_of(' ', i);
        }
        else
        {
            int v1 = stk.top();
            stk.pop();
            if (s[i] == '+')
                stk.top() += v1;
            else if (s[i] == '-')
                stk.top() -= v1;
            else if (s[i] == '*')
                stk.top() *= v1;
        }
    }
    std::cout << stk.top() << std::endl;
    return 0;
}
