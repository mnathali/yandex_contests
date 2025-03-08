#include <iostream>
int global{};
unsigned long long factorial(int n) {
    unsigned long long result = 1;
    for (int i = 2; i <= n; ++i) {
        result = (result * i);
    }
    return result;
}

unsigned long long piece_of_factorial(int k, int n)
{
    unsigned long long result = 1;
    for(int t1 = k, t2 = n; t1 > 0; --t1, --t2)
    {
        result = result * t2;
    }
    return result;
}

unsigned long long countArrangements(int n, int m) {
    if (n == 0 || m == 1)
        global+= 1;
    if (n == 0) return 1;
    if (m == 0) return 0;
    if (m == 1) return factorial(n);

    unsigned long long total = 0;
    for (int k = n; k >= 0; --k) {
        total += (piece_of_factorial(k, n) * countArrangements(n - k, m - 1));
    }
    return total;
}


int main(int argc, char const *argv[])
{
    int n, m;

    std::cin >> n >> m;
    std::cout << countArrangements(n, m) << std::endl;
    std::cout << piece_of_factorial(n, n + m - 1) << std::endl;
    std::cout << global << " : " << global * factorial(n) << std::endl;
    return 0;
}
