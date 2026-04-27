#include <iostream>

int main()
{
    int x{ 5 };
    int& ref { x };   // reference to x 
    int* ptr { &x };  // get a pointer to x 
    
    std::cout << x;
    std::cout << ref;
    std::cout << *ptr << '\n';

    ref = 6;
    std::cout << x;
    std::cout << ref;
    std::cout << *ptr << '\n';

    *ptr = 7;
    std::cout << x;
    std::cout << ref;
    std::cout << *ptr << '\n';

    return 0;
}
