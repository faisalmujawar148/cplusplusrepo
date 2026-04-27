#include <iostream>
#include <string_view>

enum class Color
{
    black,
    red,
    blue,
};

constexpr std::string_view getColor(Color color)
{
    using enum Color;

    switch(color)
    {
        case black: return "black";
        case red:   return "red";
        case blue:  return "blue";
        default:    return "???";
    }
}

int main()
{
    Color shirt { Color::blue };

    std::cout << "Your shirt is " << getColor(shirt) << '\n';

    return 0;
}
