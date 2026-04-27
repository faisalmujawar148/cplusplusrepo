#include <iostream>

int main()
{
    //case 1
    const double& r1 { 5 };  // temporary double initialised with value 5, r1 binds to temporary 

    std::cout << r1 << '\n'; // prints 5
    
    // case 2
    char c { 'a' };
    const int& r2 { c };     // temporary int initialised with value 'a', r2 binds to temporary
   
    std::cout << r2 << '\n'; // prints 97 (since r2 is a reference to int)

    return 0;
}

// in both cases we have a temporary object.
