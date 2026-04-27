#include <iostream>
#include <optional> // for std::optional (C++17)

// Our function optional returns an int value 
std::optional<int> doIntDivision(int x, int y)
{
    if(y == 0)
        return {};  // or return std::nullopt
    return x / y;
}

int main()
{
    std::optional<int> result1 { doIntDivision(20, 5) };
    if(result1) // if the function returned a value 
        std::cout << "Result 1: " << *result1 << '\n'; // get the value 
    else 
        std::cout << "Result 1: failed \n";

    std::optional<int> result2 { doIntDivision(5, 0) };

    if(result2) // if the function returned a value 
        std::cout << "Result 2: " << *result2 << '\n'; // get the value 
    else 
        std::cout << "Result 2: failed \n";

    return 0;
}

/*
 * doIntDivision() now returns `std::optional<int>` type instead of `int`. If we detect an error we return `{}` or `std::nullopt`.
*/
