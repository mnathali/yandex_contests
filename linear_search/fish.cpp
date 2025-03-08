#include <iostream>
#include <iterator>
#include <vector>
#include <algorithm>

int main(int argc, char const *argv[])
{
    int n, k, sum{};
    std::vector<int> v;
    std::cin >> n >> k;
    std::copy(std::istream_iterator<int>(std::cin), std::istream_iterator<int>(), std::back_inserter(v));
    for (int i{0}, j{1}; j < n && i < n;)
    {
        if (v[j] - v[i] > sum)
            sum = v[j] - v[i];
        // std::cout << i << " " << j << " " << sum << std::endl;
        if (!(j - i < k) || (i < j && v[i] > v[i+1]) || j + 1 >= n || v[j] < v[i])
            ++i;
        else
            ++j;
    }
    std::cout << sum << std::endl;
    return 0;
}
