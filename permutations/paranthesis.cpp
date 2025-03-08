#include <iostream>
#include <vector>

template<typename T>
std::ostream& operator<<(std::ostream& o, const std::vector<T>& vec)
{
    // o << '[';
    for (typename std::vector<T>::const_iterator it = vec.begin(); it < vec.end(); ++it)
        o << *it << " ";
    // o << ']';
    return o;
}

bool is_valid(std::string &s) {
        std::string str;
        for (std::string::iterator it = s.begin(); it < s.end(); ++it)
        {
            if (*it == '(' || *it == '[' || *it == '{')
                str.append(1, *it);
            else
            {
                if (str.size() == 0 || (*it == ')' && *str.rbegin() != '(')
                || (*it == ']' && *str.rbegin() != '[')
                || (*it == '}' && *str.rbegin() != '{'))
                    return false;
                else
                    str.erase(str.size() - 1);
            }
        }
        if (str.size())
            return false;
        return true;
    }

void recursion(std::string &s, int n, int d, std::vector<int> &counter)
{
    if (d == n)
    {
        if (is_valid(s))
            std::cout << s << std::endl;
        return;
    }
    for (auto el : {'(', '[', ')', ']'})
    {
        s[d] = el;
        switch (el)
        {
        case '(':
            counter[0] += 1;
            break;
        case '[':
            counter[1] += 1;
            break;
        case ')':
            counter[2] += 1;
            break;
        case ']':
            counter[3] += 1;
            break;
        }
        bool flag = true;
        if (counter[2] > counter[0] || counter[3] > counter[1] || counter[0] + counter[1] > n / 2
            || counter[0] > n/2 || counter[1] > n/2 || counter[2] > n/2 || counter[3] > n/2)
            flag = false;
        if (flag)
            recursion(s, n, d+1, counter);
                switch (el)
        {
        case '(':
            counter[0] -= 1;
            break;
        case '[':
            counter[1] -= 1;
            break;
        case ')':
            counter[2] -= 1;
            break;
        case ']':
            counter[3] -= 1;
            break;
        }

    }
}


int main(int argc, char const *argv[])
{
    int n;
    std::cin >> n;
    std::string s;
    std::vector<int> counter(4, 0);
    s.resize(n);
    recursion(s, n, 0, counter);

    return 0;
}
