#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <map>
#include <set>
#include <vector>
#include <string>

template<typename T>
std::ostream& operator<<(std::ostream& o, const std::unordered_set<T>& vec)
{
    o << '[';
    for (typename std::unordered_set<T>::const_iterator it = vec.begin(); it != vec.end(); ++it)
        o << *it << ",";
    o << ']';
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

int find_common(const std::string &s1,
                const std::string &s2,
                const std::string &s3,
                const std::unordered_map<std::string, std::vector<std::string>> &ump,
                std::string &s)
{
    int i{};
    if (s1 == s3)
        ++i;
    if (s2 == s3)
        ++i;
    if (i == 2)
        s = s3;
    auto parent = ump.find(s3);
    if (parent != ump.end() && s.empty())
    {
        for (auto &child: parent->second)
        {
            i += find_common(s1, s2, child, ump, s);
            if (!s.empty())
                break;
            if (i == 2)
                s = s3;
        }
    }
    // std::cout << i  << " " << s3 << std::endl;
    return i;
}

int main(int argc, char const *argv[])
{
    int n;
    std::cin >> n;
    std::unordered_map<std::string, std::vector<std::string>> ump;
    std::unordered_map<std::string, std::string> ump1;
    std::map<std::string, int> mp;
    for (int i{}; i < n - 1; ++i)
    {
        std::string s1, s2;
        std::cin >> s1 >> s2;
        ump[s2].emplace_back(s1);
        ump1[s1] = s2;
    }
    std::string s;
    std::unordered_set<std::string> st1, st2;
    for (auto &el: ump)
    {
        st2.insert(el.first);
        st1.insert(el.second.begin(), el.second.end());
    }
    for (auto &el: st1)
        st2.erase(el);
    std::string root = *st2.begin();
    ump1[root] = "";
    std::getline(std::cin, s);
    // for (auto &el: ump)
    //     std::cout << el.first << ": " << el.second << std::endl;
    while (std::getline(std::cin, s))
    {
        std::string s1, s2;
        s1 = s.substr(0, s.find_first_of(' '));
        s2 = s.substr(s.find_first_of(' ') + 1);
        // s.clear();
        // find_common(s1, s2, root, ump, s);
        // std::cout << s << std::endl;

        std::unordered_set<std::string> st3;
        auto it = ump1.find(s2);
        st3.insert(s2);
        while (it != ump1.end())
        {
            st3.insert(it->first);
            st3.insert(it->second);
            it = ump1.find(it->second);
        }
        //std::cout << st3 << " " << ump1["Alexei"] << std::endl;
        it = ump1.find(s1);
        while (st3.find(it->first) == st3.end())
        {
            //std::cout << it->first << std::endl;
            it = ump1.find(it->second);
        }
        std::cout << it->first << std::endl;
    }
    return 0;
}
