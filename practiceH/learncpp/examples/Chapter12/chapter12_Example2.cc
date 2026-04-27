#include <iostream>

int main()
{
    int x { 5 };
    int& ref { x };

    std::cout << x << ref << '\n';

    x = 6;

    std::cout << x << ref << '\n';

    ref = 7;

    std::cout << x << ref << '\n';

    return 0;
}
