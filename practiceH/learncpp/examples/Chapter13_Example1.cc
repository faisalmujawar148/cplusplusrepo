#include <iostream>

enum Color
{
    red,
    green,
    blue,
};

int main()
{
    Color apple { red };
    Color shirt { green };
    Color cup { blue };

    std::cout << apple << '\n';
}
