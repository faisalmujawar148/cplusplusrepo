#include <iostream>
#include <type_traits> // for underlying_type_t

enum class Animals
{
    chicken,
    dog,
    cat,
    elephant,
    duck,
    snake,

    maxAnimals,
};

/*
 * Overloading the unary + operator to convert an enum to an underlying type 
*/
template <typename T>
constexpr auto operator+(T a) noexcept
{
    return static_cast<std::underlying_type_t<T>>(a);
}

int main()
{
    std::cout << +Animals::elephant << '\n'; // convert Animals::elephant to an integer using unary operators

    return 0;
}
