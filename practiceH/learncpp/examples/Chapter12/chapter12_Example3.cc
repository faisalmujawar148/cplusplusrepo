#include <iostream>

int main()
{
    const int x { 5 };
    const int& ref { x };      // okay: ref is an lvalue reference to a const value 

    std::cout << ref << '\n';  // okay: we can access const value 
    // ref = 6;                   // error: we cannot modify an object through a const variable
    

    return 0;
}
