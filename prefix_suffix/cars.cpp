#include <iostream>
#include <unordered_set>

int main(int argc, char const *argv[])
{
    int n{}, k{};
    std::unordered_set<long> set;
    long sum{};
    int counter{};
    std::cin >> n >> k;
    set.insert(0);
    for (int i = 0; i < n; ++i)
    {
        int val;
        std::cin >> val;
        sum += val;
        set.insert(sum);
        if (set.find(sum - k) != set.end())
            ++counter;
    }
    std::cout << counter << std::endl;
    return 0;
}
