#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

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
    int n;
    unsigned long long c;
    std::cin >> n >> c;
    std::string s;
    s.reserve(n);
    std::cin >> s;
    unsigned long long rude = 0;
    int count_b{}, count_a{};
    int len{}, max_len{};
    auto it_a = std::find(s.begin(), s.end(), 'a');
    auto it_b = std::find(it_a, s.end(), 'b');
    if (it_a == s.end() || it_b == s.end())
    {
        std::cout << s.size() << std::endl;
        return 0;
    }
    it_a = s.begin();
    it_b = it_a;
    if (*it_a == 'a')
        ++count_a;
    if (*it_b == 'b')
        ++count_b;
    max_len = len = 1;
    while (it_b != s.end())
    {
        //std::cout << len << " " << rude << " " << max_len << std::endl;
        if (rude > c)
        {
            if (*it_a == 'a')
            {
                rude -= count_b;
                --count_a;
            }
            else if (*it_a == 'b')
                --count_b;
            ++it_a;
            --len;
        }
        else
        {
            ++it_b;
            if (it_b != s.end())
            {
                ++len;
                if (*it_b == 'b')
                {
                    rude += count_a;
                    ++count_b;
                }  
                else if (*it_b == 'a')    
                    ++count_a;      
            }
        }
        if (rude <= c && len > max_len)
            max_len = len;
    }
    std::cout << max_len << std::endl;
    return 0;
}
