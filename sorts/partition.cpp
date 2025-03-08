#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <iterator>

template<typename T>
std::ostream& operator<<(std::ostream& o, const std::vector<T>& vec)
{
    o << '[';
    for (typename std::vector<T>::const_iterator it = vec.begin(); it < vec.end(); ++it)
        o << *it << ',';
    o << ']';
    return o;
}

std::size_t partition(std::vector<int> &A, std::size_t p, std::size_t r, int x)
{
	std::size_t i = p;

	for (std::size_t j = p; j < r; ++j)
	{
		if (A[j] <= x)
		{
			std::swap(A[i], A[j]);
			i += 1;
		}
	}
	std::swap(A[i], A[r]);
	return (i);
}

int main(int argc, char const *argv[])
{
    int n, x;
    std::string s;
    std::vector<int> v;

    std::cin >> n;
    std::cin.get();
    std::getline(std::cin, s);
    std::stringstream ss(s);
    v.reserve(n);
    std::copy(std::istream_iterator<int>(ss), std::istream_iterator<int>(), std::back_inserter(v));
    std::cin >> x;
    
    if (n > 0)
        partition(v, 0, n-1, x);
    
    n = std::count_if(v.begin(), v.end(), [x](int y){ return y < x; });
    
    std::cout << n << std::endl;
    std::cout << v.size() - n << std::endl;

    return 0;
}
