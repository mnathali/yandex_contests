#include <iostream>
#include <stack>

int main(int argc, char const *argv[])
{
    std::string s;
    std::cin >> s;
    std::stack<char> stk;

    for (auto c: s)
    {
        if (c == '(' || c == '[' || c == '{')
            stk.push(c);
        else if (!stk.empty() && (c == ')' && stk.top() == '(' || c == ']' && stk.top() == '[' || c == '}' && stk.top() == '{'))
            stk.pop();
        else
        {
            std::cout << "no" << std::endl;
            return 0;
        }

    }
    if (stk.empty())
        std::cout << "yes" << std::endl;
    else
        std::cout << "no" << std::endl;
    return 0;
}
