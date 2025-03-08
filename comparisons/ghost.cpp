#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>

int main(int argc, char const *argv[])
{
    unsigned p = 1000000007;
    unsigned x = 257;
    int n,m;
    std::vector<int> input;
    std::cin >> n >> m;
    std::cin.get();
    input.reserve(n);
    std::copy(std::istream_iterator<int>(std::cin), std::istream_iterator<int>(), std::back_inserter(input));

    std::vector<std::pair<unsigned long, unsigned long>> v(input.size() + 1);
    std::vector<std::pair<unsigned long, unsigned long>> v_reverse(input.size() + 1);
    v[0].first = 0;
    v[0].second = 1;
    v_reverse[0].first = 0;
    v_reverse[0].second = 1;
    for (int i = 0; i < input.size(); ++i)
    {
        v[i+1].first = (v[i].first * x + input[i]) % p;
        v[i+1].second = (v[i].second * x) % p;
        v_reverse[i+1].first = (v_reverse[i].first * x + input[input.size() - 1 - i]) % p;
        v_reverse[i+1].second = (v_reverse[i].second * x) % p;
    }

    for (int i = n / 2 ; i <= n; ++i)
    {
        if ((v[n - i].first + v_reverse[2 * i - n].first * v_reverse[n - i].second) % p
            == (v_reverse[i].first) % p)
            std::cout << i << " ";
    }
    std::cout << std::endl;

    return 0;
}



// int main(int argc, char const *argv[])
// {
//     int n,m;
//     std::string s;
//     std::string s_copy;
//     std::list<int> v;
//     std::cin >> n >> m;
//     std::cin.get();
//     s.reserve(2 * n);

//     std::copy(std::istream_iterator<char>(std::cin), std::istream_iterator<char>(), std::back_inserter(s));
//     s_copy = s;
//     for (int i = 0; i <= n / 2; ++i)
//     {
//         std::copy(s.rbegin(), s.rend(), std::back_inserter(s));
//         if (std::string_view s_v = std::string_view(s).substr(s.size() - n); s_v == s_copy)
//             v.push_front(n-i);
//         s.resize(n - i - 1);
//     } 
//     for (auto el : v)
//         std::cout << el << " ";
//     std::cout << std::endl;
//     return 0;
// }
