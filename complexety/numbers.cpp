#include <iostream>
#include <algorithm>
#include <vector>
#include <iterator>

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
    int n, sum{};
    std::vector<int> v;
    std::cin >> n;
    std::copy(std::istream_iterator<int>(std::cin), std::istream_iterator<int>(), std::back_inserter(v));
    std::string s(n-1, '+');
    for (int i{0}; i < v.size(); ++i)
        sum += v[i];
    int i{};
    for (; sum % 2 == 0; ++i)
    {
        sum += v[i] * v[i+1] - (v[i] + v[i+1]);
        if (sum % 2 != 0)
            s[i] = 'x';
    }
    std::cout << s << std::endl;
    return 0;
}
