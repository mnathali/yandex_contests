#include <iostream>
#include <vector>
#include <stack>

int main(int argc, char const *argv[])
{
    int n;
    std::cin >> n;

    std::vector<std::pair<int, int>> v;
    std::vector<int> b;
    std::stack<std::pair<int, int>> stk;
    v.reserve(n);
    b.resize(n, -1);
    for (int i{}; i < n; ++i)
    {
        int val;
        std::cin >> val;
        v.push_back({val, i});
    }
    for (int i{}; i < n; ++i)
    {
        while (!stk.empty() && stk.top().first > v[i].first)
        {
            b[stk.top().second] = i;
            stk.pop();
        }
        stk.push(v[i]);
    }
    for (auto i: b)
        std::cout << i << " ";
    std::cout << std::endl;
    return 0;
}
