#include <iostream>
#include <optional>
#include <string>
#include <string_view>

enum Pet 
{
    cat,
    dog,
    pig,
    whale,
};

constexpr std::string_view getPetName(Pet pet)
{
    switch(pet)
    {
        case cat: 
            return "cat";
        case dog:
            return "dog";
        case pig:
            return "pig";
        case whale:
            return "whale";
        default: 
            return "???";
    }
}

constexpr std::optional<Pet> getPetFromString(std::string_view sv)
{
    if(sv == "cat") return cat;
    if(sv == "dog") return dog;
    if(sv == "pig") return pig;
    if(sv == "whale") return whale;

    return std::nullopt;
}

int main()
{
    std::cout << "Enter a pet: cat, dog, pig, whale: ";
    std::string s {};
    std::cin >> s;

    std::optional<Pet> pet { getPetFromString(s) };

    if(!pet)
        std::cout << "You've entered an invalid pet \n";
    else
        std::cout << "You entered: " << getPetName(*pet) << '\n';

    return 0;
}
