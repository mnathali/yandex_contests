#include <iostream>
#include <algorithm>

int main(int argc, char const *argv[])
{
    long P, V, Q, M;
    std::cin >> P >> V >> Q >> M;
    auto p = P <= Q ? P : Q, v = P <= Q ? V : M;
    auto q = P > Q ? P : Q, m = P > Q ? V : M;
    long max = std::max(p+v, q+m) - std::min(p-v, q-m) + 1;
    if (p+v < q-m)
        max -= q-m - (p+v) - 1;
    std::cout << max << std::endl;
    return 0;
}
