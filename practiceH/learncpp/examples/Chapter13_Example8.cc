#include <iostream>

int main()
{
    enum class Pet 
    {
        cat,
        dog,
        pig,
        whale,
    };

    std::cout << "Enter a pet (0=cat, 1=dog, 2=pig, 3=whale): ";

    int input{};
    std::cin >> input; // input an integer 
    
    Pet pet{ static_cast<Pet>(input) };

    return 0;
}


