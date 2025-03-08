#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#define MOD 1000000000000000000

template<typename T>
std::ostream& operator<<(std::ostream& o, const std::pair<T, T>& pair)
{
    o <<  "{" << pair.first << " , " << pair.second << "}";
    return o;
}
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
    std::cin >> n;
    std::vector<int> v = std::vector<int>();
    std::vector<unsigned long long> v1 = std::vector<unsigned long long>();
    std::vector<unsigned long long> v2 = std::vector<unsigned long long>();
    std::vector<std::pair<unsigned long long, unsigned long long>> v3 = std::vector<std::pair<unsigned long long, unsigned long long>>();
    std::vector<std::pair<unsigned long long, unsigned long long>> v4 = std::vector<std::pair<unsigned long long, unsigned long long>>();
    std::vector<std::pair<unsigned long long, unsigned long long>> v5 = std::vector<std::pair<unsigned long long, unsigned long long>>();
    v.reserve(n);
    v1.reserve(n+1);
    v2.reserve(n+1);
    v3.reserve(n);
    v4.reserve(n);
    v5.reserve(n);
    std::copy(std::istream_iterator<int>(std::cin), std::istream_iterator<int>(), std::back_inserter(v));
    v1.push_back(0);
    v2.push_back(0);
    for (int i{}; i < n; ++i)
    {
        v1.push_back(v1.back() + v[i]);
        v2.push_back(v2.back() + v[n - 1 - i]);
    }
    for (int i{}; i < n; ++i)
    {
        v3.push_back({v1[i] / MOD + (v3.empty() ? 0 : v3.back().first) + (v1[i] % MOD + (v3.empty() ? 0 : v3.back().second)) / MOD,
                        (v1[i] % MOD + (v3.empty() ? 0 : v3.back().second)) % MOD});
        v4.push_back({v2[i] / MOD + (v4.empty() ? 0 : v4.back().first) + (v2[i] % MOD + (v4.empty() ? 0 : v4.back().second)) / MOD,
                        (v2[i] % MOD + (v4.empty() ? 0 : v4.back().second)) % MOD});
    }
    for (int i{}; i < n; ++i)
    {
        v5.push_back({v3[i].first + v4[n - 1 - i].first + (v3[i].second + v4[n - 1 - i].second) / MOD,
                        (v3[i].second + v4[n - 1 - i].second) % MOD});
    }
    // std::cout << v1 << std::endl;
    // std::cout << v2 << std::endl;
    // std::cout << v3 << std::endl;
    // std::cout << v4 << std::endl;
    // std::cout << v5 << std::endl;
    auto it = std::min_element(v5.begin(), v5.end(), [](auto &l, auto &r){
        return l.first == r.first ? l.second < r.second : l.first < l.second;
    });
    std::cout << MOD * it->first + it->second << std::endl;
    return 0;
}
