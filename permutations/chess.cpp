#include <iostream>
#include <vector>
#include <ranges>

bool restricted(int i, int j, std::vector<int>& restrictions, int n)
{
    bool flag = false;
    for (auto el : restrictions)
    {
        if (i == el)
        {
            flag = true;
            break;
        }
        else if (i + j + n == el)
        {
            flag = true;
            break;
        }
        else if (i - j - n == el)
        {
            flag = true;
            break;
        }
    }
    return flag;
}

void recursive(int n, int &count, int j = 0, std::vector<int>&& restrictions = std::vector<int>())
{
    if (j == n)
    {
        ++count;
        return;
    }
    int local_count = 0;
    for (auto i: std::views::iota(0,n))
    {
        if (restricted(i, j, restrictions, n))
            continue;
        restrictions.push_back(i);
        restrictions.push_back(j + i + n);
        restrictions.push_back(i - j - n);
        recursive(n, count, j+1, std::forward<std::vector<int>>(restrictions));
        restrictions.erase(restrictions.begin() + restrictions.size() - 3, restrictions.end());
    }
}

int main(int argc, char const *argv[])
{
    int n;

    std::cin >> n;

    int count{};

    recursive(n, count);
    std::cout << count << std::endl;
    return 0;
}
