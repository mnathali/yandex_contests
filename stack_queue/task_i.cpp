#include <iostream>
#include <list>
#include <vector>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    int n, a, b, t{1};
    std::cin >> n >> a >> b;
    std::list<std::pair<int, int>> lst[4];
    std::vector<int> v;
    for (int i{}; i < n; ++i)
    {
        int d, t_i;
        std::cin >> d >> t_i;
        lst[d-1].push_back({t_i, i});
    }
    v.resize(n);
    int c = a == 1 ? (b == 2 ? 3 : 2) : (b == 1 ? (a == 2 ? 3 : 2) : 1);
    int d = 10 - (a + b + c);
    for (auto &l: lst)
    {
        l.sort();
    }
    if (std::abs(a - b) == 2)
    {
        while (!lst[0].empty() || !lst[1].empty() || !lst[2].empty() || !lst[3].empty())
        {
            bool status = false;
            if (!lst[a-1].empty() && lst[a-1].front().first <= t)
            {
                v[lst[a-1].front().second] = t;
                lst[a-1].pop_front();
                status = true;
            }
            if (!lst[b-1].empty() && lst[b-1].front().first <= t)
            {
                v[lst[b-1].front().second] = t;
                lst[b-1].pop_front();
                status = true;
            }
            if (!status && !lst[c-1].empty() && lst[c-1].front().first <= t)
            {
                v[lst[c-1].front().second] = t;
                lst[c-1].pop_front();
            }
            if (!status && !lst[d-1].empty() && lst[d-1].front().first <= t)
            {
                v[lst[d-1].front().second] = t;
                lst[d-1].pop_front();
            }
            ++t;
        }
    }
    else
    {
        while (!lst[0].empty() || !lst[1].empty() || !lst[2].empty() || !lst[3].empty())
        {
            if (!lst[a-1].empty() && lst[a-1].front().first <= t)
            {
                if (!lst[b-1].empty() && lst[b-1].front().first <= t)
                {
                    if (b % 4 != a - 1)
                    {
                        v[lst[a-1].front().second] = t;
                        lst[a-1].pop_front();
                    }
                    else
                    {
                        v[lst[b-1].front().second] = t;
                        lst[b-1].pop_front();
                    }
                }
                else
                {
                    v[lst[a-1].front().second] = t;
                    lst[a-1].pop_front();
                    // if (!lst[(((a+2)>4)?((a+2)%4):(a+2))-1].empty() && lst[(((a+2)>4)?((a+2)%4):(a+2))-1].front().first <= t)
                    // {
                    //     if (lst[(((a+1)>4)?((a+1)%4):(a+1))-1].empty() || lst[(((a+1)>4)?((a+1)%4):(a+1))-1].front().first > t)
                    //     {
                    //         v[lst[(((a+2)>4)?((a+2)%4):(a+2))-1].front().second] = t;
                    //         lst[(((a+2)>4)?((a+2)%4):(a+2))-1].pop_front();
                    //     }
                    // }
                }
            }
            else if (!lst[b-1].empty() && lst[b-1].front().first <= t)
            {
                v[lst[b-1].front().second] = t;
                lst[b-1].pop_front();
                // if (!lst[(((b+2)>4)?((b+2)%4):(b+2))-1].empty() && lst[(((b+2)>4)?((b+2)%4):(b+2))-1].front().first <= t)
                // {
                //     if (lst[(((b+1)>4)?((b+1)%4):(b+1))-1].empty() || lst[(((b+1)>4)?((b+1)%4):(b+1))-1].front().first > t)
                //     {
                //         v[lst[(((b+2)>4)?((b+2)%4):(b+2))-1].front().second] = t;
                //         lst[(((b+2)>4)?((b+2)%4):(b+2))-1].pop_front();
                //     }
                // }
            }
            else if (!lst[c-1].empty() && lst[c-1].front().first <= t)
            {
                if (d % 4 != c - 1 || lst[d-1].empty() || lst[d-1].front().first > t)
                {
                    v[lst[c-1].front().second] = t;
                    lst[c-1].pop_front();
                }
                else
                {
                    v[lst[d-1].front().second] = t;
                    lst[d-1].pop_front();
                }
            }
            else if (!lst[d-1].empty() && lst[d-1].front().first <= t)
            {
                v[lst[d-1].front().second] = t;
                lst[d-1].pop_front();
            }
            ++t;
        }
    }
    for (auto r: v)
        std::cout << r << std::endl;
    return 0;
}
