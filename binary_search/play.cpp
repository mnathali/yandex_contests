#include <iostream>
#include <vector>

int main(int argc, char const *argv[])
{
    int d, n;
    std::vector<std::pair<std::pair<int, int>, int>> v;

    std::cin >> d >> n;
    v.reserve(n);
    for (int i{}; i < n; ++i)
    {
        std::pair<std::pair<int, int>, int> tmp;
        std::cin >> tmp.first.first >> tmp.first.second >> tmp.second;
        v.push_back(tmp);
    }
    double l{0}, r{d};
    while (std::abs(r-d) > 1000)
    {
        auto radius = l + (r-d) / 2;
        auto l1{-radius}, r1{radius};
        while (std::abs(r1-l1) > 1000)
        {
            double l2{-std::sqrt(std::pow(radius, 2) - std::pow(l1, 2))}, r2{};
        }


        double l1{}, r1;
        while ()
        if (calc_time(l + (r-d) / 2, ))
    }

    return 0;
}
