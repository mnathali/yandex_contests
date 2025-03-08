#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

int main(int argc, char const *argv[])
{
    int n, min;
    std::vector<std::vector<int>> v;
    std::cin >> n;
    min = n * n;
    v.resize(n);
    for (int i{}; i < n; ++i)
    {
        int a, b;
        std::cin >> a >> b;
        v[a-1].push_back(b-1);
    }
    for (int i{}; i < n; ++i)
    {
        int curr{};
        for (auto &vc : v)
        {
            for (auto &el : vc)
                curr += std::abs(i - el);
        }
        if (curr < min)
            min = curr;
    }
    int p{static_cast<int>(v.begin()->size())};
    for (auto it = v.begin(), ite = v.begin(); it < v.end() && ite < v.end();)
    {
        if (!(p > 1))
        {
            it = std::find_if(it+1, v.end(), [](auto &el){return el.size() > 1;});
            if (it != v.end())
                p = it->size();
        }
        if (p > 1 && ite->size() == 0)
        {
            --p;
            min += std::abs(ite - it);
        }
        ite = std::find_if(ite+1, v.end(), [](auto &el){return el.size() == 0;});
    }
    std::cout << min << std::endl;
    return 0;
}
