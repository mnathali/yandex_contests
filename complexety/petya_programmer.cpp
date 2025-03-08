#include <iostream>
#include <algorithm>
#include <vector>

template<typename T>
std::ostream& operator<<(std::ostream& o, const std::vector<T>& vec)
{
    o << '[';
    for (typename std::vector<T>::const_iterator it = vec.begin(); it < vec.end(); ++it)
        o << *it << ' ';
    o << ']';
    return o;
}

int main(int argc, char const *argv[])
{
    int n;
    std::cin >> n;

    unsigned long long res{};

    for (int i{}; i < n; ++i)
    {
        unsigned long space;
        std::cin >> space;
        res += space / 4 + (space % 4 > 2 ? 2 : space % 4);
    }
    std::cout << res << std::endl;
    return 0;
}
