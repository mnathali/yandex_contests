#include <iostream>
#include <vector>
#include <set>
#include <tuple>

template<typename T>
std::ostream& operator<<(std::ostream& o, const std::vector<T>& vec)
{
    o << '[';
    for (typename std::vector<T>::const_iterator it = vec.begin(); it < vec.end(); ++it)
        o << *it << ",";
    o << ']';
    return o;
}

int main(int argc, char const *argv[])
{
    int n;
    auto comp = [](const std::tuple<int, int, int>& l, const std::tuple<int, int, int>& r) {
        const auto [a1, b1, i1] = l;
        const auto [a2, b2, i2] = r;
        return a1 == a2 ? (b1 == b2 ? i1 < i2 : b1 > b2) : a1 > a2;
    };
    std::cin >> n;
    std::vector<int> a, b, p;
    std::set<std::tuple<int, int, int>, decltype(comp)> set_a(comp), set_b(comp);
    a.reserve(n);
    b.reserve(n);
    p.reserve(n);
    for (int i{}; i < n; ++i)
    {
        int val;
        std::cin >> val;
        a.push_back(val);
    }
    for (int i{}; i < n; ++i)
    {
        int val;
        std::cin >> val;
        b.push_back(val);
    }
    for (int i{}; i < n; ++i)
    {
        int val;
        std::cin >> val;
        p.push_back(val);
        set_a.insert({a[i], b[i], i});
        set_b.insert({b[i], a[i], i});
    }
    for (int i{}, index; i < n; ++i)
    {
        if (p[i])
        {
            const auto [a1, b1, i1] = *(set_b.begin());
            set_a.erase({a[i1], b[i1], i1});
            set_b.erase(set_b.begin());
            index = i1;
        }
        else
        {
            const auto [a2, b2, i2] = *(set_a.begin());
            set_b.erase({b[i2], a[i2], i2});
            set_a.erase(set_a.begin());
            index = i2;
        }
        std::cout << index + 1 << " ";
    }
    
    std::cout << std::endl;
    return 0;
}
