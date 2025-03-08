#include <iostream>
#include <map>
#include <unordered_map>
#include <vector>
#include <set>

int calculate_children(std::string name, const std::unordered_map<std::string, std::vector<std::string>> &ump, std::map<std::string, int> &mp)
{
    auto parent = ump.find(name);
    if (parent != ump.end())
    {
        int i{0};
        for (auto &child: parent->second)
            i += calculate_children(child, ump, mp);
        mp[name] = i;
        return i + 1;
    }
    mp[name] = 0;
    return 1;
}

int main(int argc, char const *argv[])
{
    int n;
    std::cin >> n;
    std::unordered_map<std::string, std::vector<std::string>> ump;
    std::map<std::string, int> mp;
    for (int i{}; i < n - 1; ++i)
    {
        std::string s1, s2;
        std::cin >> s1 >> s2;
        ump[s2].push_back(s1);
    }
    std::set<std::string> st1, st2;
    for (auto &el: ump)
    {
        st2.insert(el.first);
        st1.insert(el.second.begin(), el.second.end());
    }
    for (auto &el: st1)
        st2.erase(el);
    std::string root = *st2.begin();
    calculate_children(root, ump, mp);
    for (auto &el: mp)
        std::cout << el.first << " " << el.second << std::endl;
    return 0;
}
