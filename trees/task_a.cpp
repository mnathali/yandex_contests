#include <iostream>
#include <unordered_map>
#include <set>

int main(int argc, char const *argv[])
{
    int n;
    std::unordered_map<std::string, std::string> umap;
    std::set<std::string> st;
    std::cin >> n;

    for (int i{}; i < n - 1; ++i)
    {
        std::string s1, s2;
        std::cin >> s1 >> s2;
        umap[s1] = s2;
        if (umap.find(s2) == umap.end())
            umap[s2] = "";
        st.insert(s1);
        st.insert(s2);
    }
    for (auto name: st)
    {
        int i{};
        auto parent = umap[name];
        while (parent != "")
        {
            parent = umap[parent];
            ++i;
        }
        std::cout << name << " " << i << std::endl;
    }
    return 0;
}
