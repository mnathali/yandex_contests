
#include <iostream>


int main(int argc, char const *argv[])
{
    int x1, y1, x2, y2, x, y;

    std::cin >> x1 >> y1 >> x2 >> y2 >> x >> y;
    if (x <= x1)
    {
        if (y >= y2)
            std::cout << "NW";
        else if (y <= y1)
            std::cout << "SW";
        else
            std::cout << "W";
    }
    else if (x >= x2)
    {
        if (y >= y2)
            std::cout << "NE";
        else if (y <= y1)
            std::cout << "SE";
        else
            std::cout << "E";
    }
    else
    {
        if (y >= y2)
            std::cout << "N";
        else
            std::cout << "S";
    }
    std::cout << std::endl;
    return 0;
}
