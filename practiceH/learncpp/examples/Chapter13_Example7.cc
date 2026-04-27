#include <iostream>
#include <utility>

int main()
{
    enum class Color 
    {
        red,
        blue,
    };
    
    Color color { Color::blue };

    std::cout << static_cast<int>(color) << '\n'; // explicit conversion to int, will print 1
    std::cout << std::to_underlying(color) << '\n'; // convert to underlying type, will print 1 (C++23)
        
    return 0;
}
