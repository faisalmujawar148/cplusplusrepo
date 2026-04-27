#include <iostream>

void printAddress(int val, int& ref)
{
    std::cout << "The address of the value parameter is: " << &val << '\n';
    std::cout << "The address of the reference parameter is: " << &ref << '\n';
}

int main()
{
    int x { 5 };
    std::cout << "The address of x is: " << &x << '\n';
    printAddress(x, x);

    return 0;
}

/*
* Here we can see that when x is copied (via val) we can see that a new object is being created (with a new address).
* Meanwhile when we pass by reference the address is the same argument x. Therefore, the ref acts like an alias for our variable x.
*/
