#include <iostream>

int main()
{
    char* chPtr {};
    int* iPtr{};
    long double* ldPtr{};

    std::cout << sizeof(chPtr) << '\n';
    std::cout << sizeof(iPtr) << '\n';
    std::cout << sizeof(ldPtr) << '\n';


    return 0;
}
