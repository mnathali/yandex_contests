#include <iostream>
#include <cmath>
#include <set>
#include <limits>
#include <iomanip>

int main(int argc, char const *argv[])
{
    int L, x1, x2, v1, v2;

    std::cin >> L >> x1 >> v1 >> x2 >> v2;
    std::cout << std::fixed;
    std::cout << std::setprecision(10);
    std::set<double> results;
    if (x2 < x1) {
        std::swap(x1, x2);
        std::swap(v1, v2);
    }
    if (v1 < 0 && v2 < 0)
    {
        v1 *= -1;
        v2 *= -1;
        x1 = L - x1;
        x2 = L - x2;
    }
    // std::cout << std::cos(30 *M_PI / 4) << std::endl;

    if (x1 == x2)
        results.insert(0);
    else
        results.insert((double)(x2 - x1) / (v1 - v2));
    results.insert((double)(L - x2 - x1) / (v1 + v2));
    results.insert((double)(x2 - L - x1) / (v1 - v2));
    results.insert((double)(x2 - (long)L - L + x1) / (- v1 - v2));
    auto it = results.lower_bound(0);
    if (it != results.end() && *it != std::numeric_limits<double>::infinity())
    {
        std::cout << "YES" << std::endl << *it << std::endl;
    }
    else
        std::cout << "NO" << std::endl;
    if (v1 * v2 < 0)
        std:: cout << (double)(x2 - x1) / (v1 - v2) << " "
        << (double)(L - x2 - x1) / (v1 + v2) << " "
        << (double)(x2 - L - x1) / (v1 - v2) << std::endl;
    else
        std::cout << (double)(x2 - x1) / (v1 - v2) << " "
        << (double)(L - x2 - x1) / (v1 + v2) << " "
        << (double)(x2 - L - L + x1) / (- v1 - v2) << " "
        << (double)(x2 - L - x1) / (v1 - v2) << " "
         << std::endl;
        

    // for (int i{}; i < 10; ++i)
    //     std::cout << std::cos((double)(x1 + v1 * i) * 2 * M_PI / L)
    //         << " " << std::cos((double)(x2 + v2 * i) * 2 * M_PI / L) << std::endl;

    // std::cout << (- (x1 * v1 - x2 * v2) + std::sqrt(std::pow(x1 * v1 - x2 * v2, 2)
    //     - (std::pow(v1, 2) - std::pow(v2, 2)) * (std::pow(x1, 2) - std::pow(x2, 2))))
    //     / (std::pow(v1, 2) - std::pow(v2, 2)) << std::endl;

    return 0;
}
