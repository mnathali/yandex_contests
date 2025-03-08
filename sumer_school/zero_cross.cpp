#include <iostream>
#include <map>

int check_field_diagonal1(std::map<std::pair<int, int>, int> &m, int a, int b, int a1, int b1, int a2, int b2)
{
    auto it = m.find({a1, b1});
    auto ite = m.find({a2, b2});
    auto score{1};
    if (it != m.end() && ite == m.end())
    {
        auto itr = m.find(std::pair{it->second, b + (it->second - a)});
        m[std::pair{a, b}] = it->second;
        itr->second = a;
        score = itr->first.first - a + 1;
    }
    else if (it == m.end() && ite != m.end())
    {
        auto itr = m.find(std::pair{ite->second, b + (ite->second - a)});
        m[std::pair{a, b}] = ite->second;
        ite->second = a;
        itr->second = a;
        score = a - itr->first.first + 1;
    }
    else if (it != m.end() && ite != m.end())
    {
        auto e = it->second;
        m[std::pair{a, b}] = e;
        m[std::pair{e, b + (e - a)}] = ite->second;
        m[std::pair{ite->second, b + (ite->second - a)}] = e;
        score = e - ite->second + 1;
        ite->second = e;
    }
    else
        m[std::pair{a, b}] = a;
    return score;
}

int check_field_diagonal2(std::map<std::pair<int, int>, int> &m, int a, int b, int a1, int b1, int a2, int b2)
{
    auto it = m.find({a1, b1});
    auto ite = m.find({a2, b2});
    auto score{1};
    if (it != m.end() && ite == m.end())
    {
        auto itr = m.find(std::pair{it->second, b - (it->second - a)});
        m[std::pair{a, b}] = it->second;
        itr->second = a;
        score = itr->first.first - a + 1;
    }
    else if (it == m.end() && ite != m.end())
    {
        auto itr = m.find(std::pair{ite->second, b - (ite->second - a)});
        m[std::pair{a, b}] = ite->second;
        ite->second = a;
        itr->second = a;
        score = a - itr->first.first + 1;
    }
    else if (it != m.end() && ite != m.end())
    {
        auto e = it->second;
        m[std::pair{a, b}] = e;
        m[std::pair{e, b - (e - a)}] = ite->second;
        m[std::pair{ite->second, b - (ite->second - a)}] = e;
        score = e - ite->second + 1;
        ite->second = e;
    }
    else
        m[std::pair{a, b}] = a;
    return score;
}

int check_field_vertical(std::map<std::pair<int, int>, int> &m, int a, int b, int a1, int b1, int a2, int b2)
{
    auto it = m.find({a1, b1});
    auto ite = m.find({a2, b2});
    auto score{1};
    if (it != m.end() && ite == m.end())
    {
        auto itr = m.find(std::pair{it->second, b});
        m[std::pair{a, b}] = it->second;
        itr->second = a;
        score = itr->first.first - a + 1;
    }
    else if (it == m.end() && ite != m.end())
    {
        auto itr = m.find(std::pair{ite->second, b});
        m[std::pair{a, b}] = ite->second;
        ite->second = a;
        itr->second = a;
        score = a - itr->first.first + 1;
    }
    else if (it != m.end() && ite != m.end())
    {
        auto e = it->second;
        m[std::pair{a, b}] = e;
        m[std::pair{e, b}] = ite->second;
        m[std::pair{ite->second, b}] = e;
        score = e - ite->second + 1;
        ite->second = e;
    }
    else
        m[std::pair{a, b}] = a;
    return score;
}

int check_field_horizontal(std::map<std::pair<int, int>, int> &m, int a, int b, int a1, int b1, int a2, int b2)
{
    auto it = m.find({a1, b1});
    auto ite = m.find({a2, b2});
    auto score{1};
    if (it != m.end() && ite == m.end())
    {
        auto itr = m.find(std::pair{a, it->second});
        m[std::pair{a, b}] = it->second;
        itr->second = b;
        score = itr->first.second - b + 1;
    }
    else if (it == m.end() && ite != m.end())
    {
        auto itr = m.find(std::pair{a, ite->second});
        m[std::pair{a, b}] = ite->second;
        ite->second = b;
        itr->second = b;
        score = b - itr->first.second + 1;
    }
    else if (it != m.end() && ite != m.end())
    {
        auto e = it->second;
        m[std::pair{a, b}] = e;
        m[std::pair{a, e}] = ite->second;
        m[std::pair{a, ite->second}] = e;
        score = e - ite->second + 1;
        ite->second = e;
    }
    else
        m[std::pair{a, b}] = b;
    return score;
}

int main(int argc, char const *argv[])
{
    int n;
    std::map<std::pair<int, int>, int> d1;
    std::map<std::pair<int, int>, int> d21;
    std::map<std::pair<int, int>, int> v1;
    std::map<std::pair<int, int>, int> g1;
    
    std::map<std::pair<int, int>, int> d2;
    std::map<std::pair<int, int>, int> d22;
    std::map<std::pair<int, int>, int> v2;
    std::map<std::pair<int, int>, int> g2;

    std::cin >> n;


    for (int i{}; n > 8 && i < n; ++i)
    {
        int a, b;
        std::cin >> a >> b;
        if (i % 2 == 0)
        {
            auto status = check_field_diagonal1(d1, a, b, a+1, b+1, a-1, b-1) > 4 
                        || check_field_diagonal2(d21, a, b, a+1, b-1, a-1, b+1) > 4 
                        || check_field_horizontal(g1, a, b, a, b+1, a, b-1) > 4 
                        || check_field_vertical(v1, a, b, a+1, b, a-1, b) > 4;
            if (status && i == n-1)
            {
                std::cout << "First" <<std::endl;
                return 0;
            }
            else if (status && i < n-1)
            {
                std::cout << "Inattention" <<std::endl;
                return 0;
            }
        }
        else
        {
            auto status = check_field_diagonal1(d2, a, b, a+1, b+1, a-1, b-1) > 4 
                        || check_field_diagonal2(d22, a, b, a+1, b-1, a-1, b+1) > 4 
                        || check_field_horizontal(g2, a, b, a, b+1, a, b-1) > 4 
                        || check_field_vertical(v2, a, b, a+1, b, a-1, b) > 4;
            if (status && i == n-1)
            {
                std::cout << "Second" <<std::endl;
                return 0;
            }
            else if (status && i < n-1)
            {
                std::cout << "Inattention" <<std::endl;
                return 0;
            }
        }
    }
    std::cout << "Draw" << std::endl;
    return 0;
}
