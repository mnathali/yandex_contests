#include <iostream>
#include <vector>
#include <algorithm>

int calc_h(std::vector<int> &a, int w1)
{
    int i{1}, j{1}, p{};

    for (auto &word : a)
    {
        p += word;
        if (p > w1)
        {
            ++i;
            p = word;
        }
        ++p;
    }
    return i;
}

int main(int argc, char const *argv[])
{
    int w, n, m, min_w1{}, min_w2{};
    std::vector<int> a, b;
    std::cin >> w >> n >> m;
    a.resize(n);
    b.resize(m);
    for (int i{}; i < n; ++i)
    {
        std::cin >> a[i];
        if (a[i] > min_w1)
            min_w1 = a[i];
    }
    for (int i{}; i < m; ++i)
    {
        std::cin >> b[i];
        if (b[i] > min_w2)
            min_w2 = b[i];
    }
    int l = min_w1, r = w - min_w2;
    auto c_l = calc_h(a, min_w1), c_r = calc_h(b,  w - min_w1);
    auto diff = c_l - c_r;
    int res = std::max(c_l, c_r);
    std::cout << c_l << " -- " << c_r << " " << l << " " << r << std::endl;
    if (diff > 0)
    {
        while (l < r-1)
        {
            c_l = calc_h(a, l + (r-l)/2);
            c_r = calc_h(b, w - (l + (r-l)/2));
            diff = c_l - c_r;
            if (diff <= 0)
                r = l + (r-l)/2;
            else
                l += (r-l)/2;
            if (std::max(c_l, c_r) < res)
                res = std::max(c_l, c_r);
        }
        auto abs = std::abs(c_l - c_r);
        std::cout << c_l << " -- " << c_r << " " << l << " " << r << std::endl;
        while (abs != 0 && l < (w - min_w2))
        {
            ++l;
            c_l = calc_h(a, l);
            c_r = calc_h(b, w - l);
            if (std::abs(c_l - c_r) > abs)
                break;
            else
                abs = std::abs(c_l - c_r);
            if (std::max(c_l, c_r) < res)
                res = std::max(c_l, c_r);
        }
    }
    std::cout << res << std::endl;
    return 0;
}
