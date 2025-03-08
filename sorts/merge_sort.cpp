#include <iostream>
#include <iterator>
#include <algorithm>
#include <vector>

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
	delete [] L;
    delete [] R;
}

void merge_sort(int *A, std::size_t p, std::size_t r)
{
	if (p + 1 < r)
	{
		std::size_t q = (p + r) / 2;
		merge_sort(A, p, q);
		merge_sort(A, q, r);
		merge(A,p,q,r);
	}
}

int main(int argc, char const *argv[])
{
    int n;
    std::vector<int> v;

    std::cin >> n;
    v.reserve(n);
    std::copy(std::istream_iterator<int>(std::cin), std::istream_iterator<int>(), std::back_inserter(v));
    merge_sort(v.data(), 0, n);
    std::cout << v << std::endl;
    return 0;
}
