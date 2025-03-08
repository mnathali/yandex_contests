#include <iostream>
#include <vector>
#include <ranges>

template<typename T>
std::ostream& operator<<(std::ostream& o, const std::vector<T>& vec)
{
    // o << '[';
    for (typename std::vector<T>::const_iterator it = vec.begin(); it < vec.end(); ++it)
        o << *it;
    // o << ']';
    return o;
}

int main(int argc, char const *argv[])
{
    int n;
    std::cin >> n;
    auto range = std::views::iota(1, n+1);
    std::vector v(range.begin(), range.end());
    std::cout << v << std::endl;
    while (std::next_permutation(v.begin(), v.end()))
        std::cout << v << std::endl;
    return 0;
}
