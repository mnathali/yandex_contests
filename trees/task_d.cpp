#include <iostream>
#include <list>
#include <vector>
#include <string>
#include <unordered_set>

typedef std::pair<int, std::pair<void*, void*>> tree_node;

void find_place(void* parent, void *child)
{
    tree_node *parent_node = static_cast<tree_node*>(parent);
    tree_node *child_node = static_cast<tree_node*>(child);
    if (child_node->first < parent_node->first)
    {
        // std::cout << "left" << std::endl;
        if (parent_node->second.first != nullptr)
            find_place(parent_node->second.first, child);
        else
            parent_node->second.first = child;
    }
    else
    {
        // std::cout << "right" << std::endl;
        if (parent_node->second.second != nullptr)
            find_place(parent_node->second.second, child);
        else
            parent_node->second.second = child;
    }
}

void print_tree(void *node, int i)
{
    tree_node *parent_node = static_cast<tree_node*>(node);
    if (parent_node->second.first)
        print_tree(parent_node->second.first, i + 1);
    for (int j{}; j < i; ++j)
        std::cout << '.';
    std::cout << parent_node->first << std::endl;
    if (parent_node->second.second)
        print_tree(parent_node->second.second, i + 1);
}

int main(int argc, char const *argv[])
{
    std::list<tree_node> lst;
    std::string s;
    std::unordered_set<int> st;
    while (std::getline(std::cin, s))
    {
        std::string s1, s2;
        int val{};
        s1 = s.substr(0, s.find(' '));
        if (s != "PRINTTREE")
        {
            s2 = s.substr(s.find(' ') + 1);
            val = std::stoi(s2);
        }
        if (s1 == "ADD")
        {
            if (st.find(val) != st.end())
                std::cout << "ALREADY" << std::endl;
            else
            {
                std::cout << "DONE" << std::endl;
                st.insert(val);
                lst.push_back({val, {nullptr, nullptr}});
                void *parent = &lst.front();
                void *child = &lst.back();
                if (lst.size() != 1)
                    find_place(parent, child);
            }
        }
        else if (s1 == "SEARCH")
        {
            if (st.find(val) != st.end())
                std::cout << "YES" << std::endl;
            else
                std::cout << "NO" << std::endl;
        }
        else
            print_tree(&lst.front(), 0);
    }
    return 0;
}
