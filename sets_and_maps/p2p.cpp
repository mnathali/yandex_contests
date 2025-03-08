#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <ranges>
#include <unordered_set>

template<typename T, typename V>
std::ostream& operator<<(std::ostream& o, const std::pair<T, V>& pair)
{
    o << '{' << pair.first << ", " << pair.second << "}";
    return o;
}

template<typename T>
std::ostream& operator<<(std::ostream& o, const std::vector<T>& vec)
{
    o << '[';
    for (typename std::vector<T>::const_iterator it = vec.begin(); it < vec.end(); ++it)
        o << *it << ",";
    o << ']';
    return o;
}

int main(int argc, char const *argv[])
{
    int n, k;

    std::cin >> n >> k;
    std::vector<int> res(n);
    std::unordered_set<int> st;
    std::vector<std::vector<bool>> v;
    std::vector<std::vector<std::pair<int, int>>> rank;
    v.resize(n, std::vector<bool>(k, false));
    rank.resize(n);
    v[0] = std::vector<bool>(k, true);

    while (st.size() < n)
    {
        std::vector<std::pair<int, int>> mp(k);
        std::vector<int> saved_unsort(n);
        std::vector<std::pair<int, int>> saved(n);
        std::vector<int> choose(n); 
        std::vector<int> request(n); 
        for (int i{}; i < n; ++i)
        {
            for (int j{}; j < k; ++j)
            {
                if (v[i][j] == true)
                {
                    ++mp[j].first;
                    ++saved_unsort[i];
                    ++saved[i].first;
                }
                mp[j].second = j;
            }
            saved[i].second = i;
            if (saved[i].first == k)
            {
                st.insert(i);
                choose[i] = k;
                request[i] = i;
            }
            else
                ++res[i];
        }
        std::ranges::sort(mp);
        std::ranges::sort(saved);
        for (int i{}; i < n; ++i)
            for (int j{}; st.count(i) == 0 && j < k; ++j)
                if (v[i][mp[j].second] == false)
                {
                    choose[i] = mp[j].second;
                    break;
                }
        for (int i{}; i < n; ++i)
            for (int j{}; st.count(i) == 0 && j < n; ++j)
                if (v[saved[j].second][choose[i]] == true)
                {
                    request[i] = saved[j].second;
                    break;
                }
        std::vector<std::pair<int, int>> connections;
        for (int i{}; i < n; ++i)
        {
            std::ranges::sort(rank[i], [&saved_unsort](auto &l, auto &r){
                if (l.first != r.first) return l.first > r.first;
                else if (saved_unsort[l.second] != saved_unsort[r.second])
                    return saved_unsort[l.second] < saved_unsort[r.second];
                else
                    return l.second < r.second;});//????
            bool check = false;
            for (auto &el : rank[i])
                if (i == request[el.second])
                {
                    v[el.second][choose[el.second]] = true;
                    check = true;
                    connections.emplace_back(i, el.second);
                    break;
                }
            if (check)
                continue;
            for (auto &el : saved)
                if (i == request[el.second] && i != el.second)
                {
                    v[el.second][choose[el.second]] = true;
                    connections.emplace_back(i, el.second);
                    break;
                }
        }
        for (auto &link : connections)
        {
            auto it = std::find_if(rank[link.second].begin(), rank[link.second].end(), [i = link.first](auto &l){
                return l.second == i;
            });
            if (it != rank[link.second].end())
                it->first += 1;
            else
                rank[link.second].push_back(std::make_pair(1, link.first));
        }


    }
    for (int i{1}; i < n; ++i)
        std::cout << res[i] << " ";
    std::cout << std::endl;
    return 0;
}
