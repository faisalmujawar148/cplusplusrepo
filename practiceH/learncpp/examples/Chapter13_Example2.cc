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
        case black:
            return "black";
        case red:
            return "red";
        case blue:
            return "blue";
        default:
            return "???";
    }    
}

int main()
{
    constexpr Color shirt{ blue };
    
    std::cout << "Your shirt is: " << getColorName(shirt) << '\n';

    return 0;
}

/*
* it's okay to use string_view here as we are using string literals which exist for the entire program.
*/
