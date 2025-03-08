#include <iostream>
#include <vector>
#include <ranges>
#include <queue>

template<typename T>
std::ostream& operator<<(std::ostream& o, const std::vector<T>& vec)
{
    o << '[';
    for (typename std::vector<T>::const_iterator it = vec.begin(); it < vec.end(); ++it)
        o << *it << ",";
    o << ']';
    return o;
}

std::vector<int> calculate_times(std::vector<std::vector<std::tuple<int, int, int>>> &roads, int prev)
{
    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> q;
    std::vector<bool> visited(prev, false);
    std::vector<int> times(prev, 2147483647);
    prev = prev - 1;
    q.push({0, prev});
    times[prev] = 0;
    while (!q.empty())
    {
        prev = q.top().second;
        q.pop();
        visited[prev] = true;
        for (auto [b, t, w] : roads[prev])
        {
            if (!visited[b])
            {
                q.push({t, b});
                if (t + times[prev] < times[b])
                    times[b] = t + times[prev];
            }
        }
    }
    return times;
}

int main(int argc, char const *argv[])
{
    int n, m;

    std::cin >> n >> m;
    std::vector<std::vector<std::tuple<int, int, int>>> roads;
    std::vector<int> times;
    roads.resize(n);
    for (auto x : std::views::iota(0, m))
    {
        int a, b, t, w;
        std::cin >> a >> b >> t >> w;
        roads[a-1].emplace_back(b-1, t, w);
        roads[b-1].emplace_back(a-1, t, w);
    }
    times = calculate_times(roads, n);

    int prev = 0;
    std::vector<int> mass(n);
    std::vector<bool> visited(n, false);
    std::priority_queue<std::pair<int, int>> q;
    q.push({0,0});
    mass[0] = 10000000;
    std::vector<int> times_rev(n);
    std::vector<int> prevs(n);
    while(!visited[n-1])
    {
        prev = q.top().second;
        q.pop();
        visited[prev] = true;
        for (auto [b, t, w] : roads[prev])
        {
            if (!visited[b])
            {
                prevs[b] = prev;
                times_rev[b] = prevs[prev] + t;
                if ((w-3000000)/100 > mass[b] && mass[prev] > mass[b] && times_rev[b] + times[b] <= 24 * 60 * 60)
                    mass[b] = mass[prev] < (w-3000000)/100 ? mass[prev] : (w-3000000)/100;
                q.push({mass[b], b});
            }
        }
    }
    // std::cout << times << std::endl;
    std::cout << mass[n-1] << std::endl;
    return 0;
}
