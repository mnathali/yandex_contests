#include <iostream>
#include <iterator>
#include <algorithm>
#include <vector>
#include <random>
#include <ranges>

std::vector<int> generate_random_vector(size_t n)
{
    std::random_device rd; // Random device to seed the random number generator
    std::mt19937 gen(rd()); // Mersenne Twister engine seeded with rd()
    std::uniform_int_distribution<int> distribution(0, 1000); // Uniform distribution from 1 to 100

    int vectorSize = n; // Number of random values you want in the vector
    std::vector<int> randomNumbers;

    randomNumbers.reserve(n);

    // Fill the vector with random values
    for (int i = 0; i < vectorSize; ++i) {
        int randomNumber = distribution(gen);
        randomNumbers.push_back(randomNumber);
    }

    return randomNumbers;
}

int random_int(size_t p, size_t n)
{
    std::random_device rd; // Random device to seed the random number generator
    std::mt19937 gen(rd()); // Mersenne Twister engine seeded with rd()
    std::uniform_int_distribution<int> distribution(0, n); // Uniform distribution from 1 to 100
    return distribution(gen);
}

template<typename T>
std::ostream& operator<<(std::ostream& o, const std::vector<T>& vec)
{
    // o << '[';
    for (typename std::vector<T>::const_iterator it = vec.begin(); it < vec.end(); ++it)
        o << *it << ' ';
    // o << ']';
    return o;
}

auto partition(std::vector<int> &A, std::size_t p, std::size_t r, int x)
{
	std::size_t i = p;
    bool status = true;

	for (std::size_t j = p; j < r; ++j)
	{
		if (A[j] <= x)
		{
			std::swap(A[i], A[j]);
            if (A[i] < A[i-1])
                status = false;
			i += 1;
		}
	}
	// std::swap(A[i], A[r]);
	return std::pair(i, status);
}

void quick_sort(std::vector<int> &A, std::size_t p, std::size_t r)
{
	if (p < r)
	{
        std::swap(A[r - 1], A[(r - p) / 2 + p]);
		auto [q, status] = partition(A, p, r, A[r - 1]);
		if (p != q - 1 && !status)
			quick_sort(A, p, q - 1);
		quick_sort(A, q, r);
	}
}

int main(int argc, char const *argv[])
{
    // int n;
    // std::vector<int> v;
    // std::cin >> n;
    // std::cin.get();
    // v.reserve(n);
    // std::copy(std::istream_iterator<int>(std::cin), std::istream_iterator<int>(), std::back_inserter(v));

    for (auto i : std::views::iota(0, 10000000))
    {
        std::vector<int> v = generate_random_vector(i);
        // std::cout << v << std::endl;
        quick_sort(v, 0, v.size());
        bool res = std::is_sorted(v.begin(), v.end());
        std::cout << i << (res ? "++++++++++++++++++++" : "-----") << std::endl;
        if (!res)
        {
            std::cout << v << std::endl;
            return 1;
        }
    }

    // quick_sort(v, 0, v.size());
    // std::cout << v << std::endl;

    return 0;
}
