#include <ios>
#include <iostream>

// Function like macro that evaluates true if the type (or object) is equal to or smaller than 
// the size of two memory addresses 

#define isSmall(T) (sizeof(T) <= 2 * sizeof(void*))

struct S 
{
    double a;
    double b;
    double c;
};

int main()
{
    std::cout << std::boolalpha; // prints true or false rather than 0 or 1 
    std::cout << isSmall(int) << '\n';

    double d{};
    std::cout << isSmall(d) << '\n';
    std::cout << isSmall(S) << '\n';

    return 0;
}
