#include <iostream>
#include <string>
#include <stack>
#include <algorithm>

int main(int argc, char const *argv[])
{
    int n;
    std::string s, w;
    std::stack<char> stk;
    std::getline(std::cin, w);
    n = std::stoi(w);
    std::getline(std::cin, w);
    std::getline(std::cin, s);
    for (auto c: s)
    {
        if (c == '(' || c == '[')
            stk.push(c);
        else
            stk.pop();
    }

    while (s.size() != n)
    {
        if (!stk.empty() && (stk.top() == '(' && w.front() == ')' || stk.top() == '[' && w.front() == ']'))
        {
            s += w.front();
            stk.pop();
        }
        else if ((w.front() == '(' || w.front() == '[') && stk.size() < n - s.size())
        {
            s += w.front();
            stk.push(w.front());
        }
        else if (stk.empty())
        {
            auto min = std::min(w.find('('), w.find('['));
            s += w[min];
            stk.push(w[min]);
        }
        else if (stk.size() < n - s.size())
        {
            auto min = std::min(w.find('('), w.find('['));
            min = std::min(min, w.find(stk.top() == '(' ? ')' : ']'));
            s += w[min];
            if (w[min] == '(' || w[min] == '[')
                stk.push(w[min]);
            else
                stk.pop();
        }
        else
        {
            s += stk.top() == '(' ? ')'  : ']';
            stk.pop();
        }
    }
    std::cout << s <<std::endl;
    return 0;
}
