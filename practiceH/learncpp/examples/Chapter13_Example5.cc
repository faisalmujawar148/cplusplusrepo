#include <iostream>
#include <string_view>

enum Color 
{
    black,
    red,
    blue,
};

constexpr std::string_view getColorName(Color color)
{
    switch(color)
    {
        case black: return "black";
        case red:   return "red";
        case blue:  return "blue";
        default:    return "???"; 
    }
}

std::ostream& operator<<(std::ostream& out, Color color)
{
    out << getColorName(color);
    return out;
}

int main()
{
    Color shirt{ blue };

    std::cout << "Your shirt is: " << shirt << '\n';

    return 0;
}
