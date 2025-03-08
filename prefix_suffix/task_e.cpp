#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <iterator>

int main(int argc, char const *argv[])
{
    std::vector<int> v;
    std::list<int> a, b;
    int n;
    std::cin >> n;
    v.reserve(n);

    std::copy(std::istream_iterator<int>(std::cin), std::istream_iterator<int>(), std::back_inserter(v));

    std::sort(v.begin(), v.end());
    a.insert(a.begin(), v.begin(), v.begin() + v.size()/2);
    b.insert(b.begin(), v.begin() + v.size()/2, v.end());
    while (!a.empty() || !b.empty())
    {
        if (a.size() >= b.size())
        {
            std::cout << a.back() << " ";
            a.pop_back();
        }
        else if (a.size() < b.size())
        {
            std::cout << b.front() << " ";
            b.pop_front();
        }
    }
    std::cout << std::endl;
    return 0;
}
