#include <iostream>
#include <vector>
#include <limits>

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
    int n{};
    unsigned long long sum{};
    std::vector<unsigned long long> v;
    std::vector<unsigned long long> matrix1;
    std::vector<unsigned long long> matrix2;
    std::vector<unsigned long long> matrix3;
    std::vector<unsigned long long> matrix4;

    std::cin >> n;

    v.reserve(n);
    matrix1.reserve(n+1);
    matrix2.reserve(n-1);
    matrix3.reserve(n);
    matrix4.reserve(n);
    matrix1.push_back(0);
    matrix3.push_back(0);
    matrix4.push_back(0);
    for (int i{}; i < n; ++i)
    {
        int val;
        std::cin >> val;
        v.push_back(val);
        matrix1.push_back(val+matrix1.back());
    }
    //std::cout << matrix1 << std::endl;
    for (int i{}; i < n - 1; ++i)
        matrix2.push_back(v[i]*(matrix1[n] - matrix1[i+1]));
    //std::cout << matrix2 << std::endl;
    for (auto s: matrix2)
    {
        matrix3.push_back(matrix3.back() + s / 1000000007 + (matrix4.back() + s % 1000000007) / 1000000007);
        matrix4.push_back((matrix4.back() + s) % 1000000007);
    }
    //std::cout << matrix3 << std::endl;
    for (int i{}; i < n - 2; ++i)
    {
        sum += (((v[i]) % 1000000007) * ((1000000007 + matrix4[n-1] - matrix4[i+1]) % 1000000007)) % 1000000007;
        sum %= 1000000007;
    }

    std::cout << sum << std::endl;
    return 0;
}
