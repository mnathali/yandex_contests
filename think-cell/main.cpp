#include "interval_map.cpp"
#include <iostream>

int main(int argc, char const *argv[])
{
    interval_map<int, char> test('A');

    test.assign(1, 9, 'B');
    test.assign(2, 7, 'A');
    test.assign(4, 7, 'B');
    // test.assign(4, 5, 'B');
    // test.assign(1, 9, 'A');
    // // test.assign(0, 10, 'b');
    // // test.assign(3, 5, 'A');
    for (int i{}; i < 10; ++i)
        std::cout << test[i] << " | " << test.get_map().size() << std::endl;
    return 0;
}
