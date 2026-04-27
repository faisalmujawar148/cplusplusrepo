#include <ios>
#include <iostream>
#include <limits>
#include <optional>

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
        case cat:   return "cat";
        case dog:   return "dog";
        case pig:   return "pig";
        case whale: return "whale";
        default:    return "???";
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
// pet is an in/out parameter 
std::istream& operator>>(std::istream& in, Pet& pet)
{
    std::string s {};
    in >> s; // get input string from user 
    
    std::optional<Pet> match { getPetFromString(s) };
    if(match)
    {
        pet = *match;
        return in;
    }
    in.setstate(std::ios_base::failbit); // input stream set to fail state 

    return in;
    
}

int main()
{
    std::cout << "Enter a pet: cat, dog, pig, whale: ";
    Pet pet{};
    std::cin >> pet;

    if(std::cin)
        std::cout << "You chose: " << getPetName(pet) << '\n';
    else 
    {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Your pet was not valid\n";
    }

    return 0; 
}
