#include <iostream>

int main(int argc, char const *argv[])
{
    std::string s1, s2, s3;
    int index{0};
    std::cin >> s1 >> s2;
    for (int i{}; i < s2.size(); ++i)
    {
        if (s2[i] == '<')
        {
            auto tmp = s2.substr(i, s2.find('>', i)-i+1);
            if (tmp == "<left>" && index > 0)
                --index;
            else if (tmp == "<right>" && index < s3.size())
                ++index;
            else if (tmp == "<delete>" && s3.size() > index)
                s3.erase(index, 1);
            else if (tmp == "<bspace>" && index > 0)
                s3.erase((index--)-1, 1);
            i = s2.find('>', i);
        }
        else
            s3.insert(s3.begin() + (index++), s2[i]);
    }
    std::cout << (s1 == s3 ? "Yes" : "No") << std::endl;
    return 0;
}
