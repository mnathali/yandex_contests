#include <iostream>
#include <vector>

template<typename T>
std::ostream& operator<<(std::ostream& o, const std::vector<T>& vec)
{
    for (typename std::vector<T>::const_iterator it = vec.begin(); it < vec.end(); ++it)
        o << *it << " ";
    return o;
}

int recoursive_parse(int i, std::vector<bool> &status, std::vector<std::vector<int>> &v, std::vector<int> &res)
{
    int count = 1;
    status[i] = true;
    for (auto j: v[i])
        count += status[j] ? 0 : recoursive_parse(j, status, v, res);
    status[i] = false;
    res[i] = count;
    return count;
}

int main(int argc, char const *argv[])
{
    int n;

    std::cin >> n;
    std::vector<std::vector<int>> v;
    std::vector<int> res;
    std::vector<bool> status;

    res.resize(n);
    v.resize(n);
    status.resize(n);

    for (int i{}; i < n-1; ++i)
    {
        int a, b;
        std::cin >> a >> b;
        v[a-1].push_back(b-1);
        v[b-1].push_back(a-1);
    }

    res[0] = recoursive_parse(0, status, v, res);
    std::cout << res << std::endl;
    return 0;
}
