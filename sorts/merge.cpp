#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>
#include <iterator>

template<typename T>
std::ostream& operator<<(std::ostream& o, const std::vector<T>& vec)
{
    // o << '[';
    for (typename std::vector<T>::const_iterator it = vec.begin(); it < vec.end(); ++it)
        o << *it << ' ';
    // o << ']';
    return o;
}

void merge(int *A, std::size_t p, std::size_t q, std::size_t r)
{
	std::size_t n_1 = q - p, n_2 = r - q;
	int *L = new int[n_1], *R = new int[n_2];

	for (std::size_t i = 0; i < n_1; ++i)
		L[i] = A[p + i];
	for (std::size_t i = 0; i < n_2; ++i)
		R[i] = A[q + i];
	for (std::size_t k = p, i = 0, j = 0; k < r; ++k)
	{
		if ((i < n_1 && L[i] <= R[j]) || !(j < n_2))
		{
			A[k] = L[i];
			i += 1;
		}
		else
		{
			A[k] = R[j];
			j += 1;
		}
	}
	delete [] L;delete [] R;
}

int main(int argc, char const *argv[])
{
    int n, m;
    std::string s;
    std::vector<int> v_1;
    std::cin >> n;
    std::cin.get();
    std::getline(std::cin, s);
    std::stringstream ss(s);
    std::copy(std::istream_iterator<int>(ss), std::istream_iterator<int>(), std::back_inserter(v_1));
    std::cin >> m;
    std::cin.get();
    std::getline(std::cin, s);
    ss.clear();
    ss.str(s);
    std::copy(std::istream_iterator<int>(ss), std::istream_iterator<int>(), std::back_inserter(v_1));
    merge(v_1.data(), 0, n, n+m);
    std::cout << v_1 << std::endl;


    return 0;
}
