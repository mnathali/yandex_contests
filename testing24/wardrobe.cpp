#include <iostream>
#include <algorithm>

int main(int argc, char const *argv[])
{
    int A, B, C, D;

    std::cin >> A >> B >> C >> D;
    int upper_bound = std::max(A, B) < std::max(C, D) ? std::max(A, B) : std::max(C, D);
    int l = std::max(A, B) < std::max(C, D) ? std::max(A, B) + 1 : 1;
    int r = std::max(A, B) < std::max(C, D) ? 1 : std::max(C, D) + 1;

    if (A * B * C * D == 0)
    {
        if (A == 0 || C == 0)
        {
            upper_bound = A == 0 ? C : A;
            l = A == 0 ? 1 : A + 1;
            r = A == 0 ? C + 1 : 1;
        }
        if (B == 0 || D == 0)
        {
            upper_bound = B == 0 ? D : B;
            l = B == 0 ? 1 : B + 1;
            r = B == 0 ? D + 1 : 1;
        }
    }
    else
    {
        if (A + C < upper_bound)
        {
            upper_bound = A + C;
            l = A + 1; r = C + 1;
        }
        if (B + D < upper_bound)
        {
            upper_bound = B + D;
            l = B + 1; r = D + 1;
        }
    }

    std::cout << l << " " << r << std::endl;

    return 0;
}
