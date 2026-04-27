# Compound Types: Enums and Structs
- C++ has two types of compound types that can be used to create program-defined types: 
    - Enumerated types (including unscoped and scoped enumerations)
    - Class types (including structs, classes, and unions)

- The definition for a program-defined type is called a type definition. 

- A program-defined type must have a name and definition before it can be used. The other compound types require neither.

```cpp
struct Fraction
{
    int numerator {};
    int denominator {};
};

int main()
{
    Fraction f { 3, 4 }; // this actually instantiates a Fraction object named f    

    return 0;
}
```
- The program-defined type named Fraction definition does not allocate any memory, it just tells the compiler what a Fraction looks like
so we can allocate objects of Fraction type later.

- By convention, program-defined types are named starting with a capital letter and don't use suffix i.e. Fraction, not fraction, fraction_t or 
Fraction_t.

- Every code file that uses program-defined type needs to see the full type definition before it is used. A forward declaration isn't enough. 
This is required so that the compiler knows how much memory to allocate for objects of that type.

- These header files are typically given the same name as the program-defined type (e.g. program-defined type named Fraction would be defined 
in Fraction.h)

- A given type is allowed to be defined in multiple code files. As forward declarations don't work, the compiler needs to see the full definition
to use a given type. We must pass the full definition to use a given type.


## Unscoped enumeration 
- An enumeration is a compound data type whose values are restricted to a set of named symbolic constants (called enumerators).
- Enums are implicitly constexpr. 
- Always name your enumerations. Start with a capital letter. Enumerators are lowercase letters.

Instead of: 

```cpp
int readFileContents()
{
    if(!openFile())
        return -1
    if(!readFile())
        return -2
    if(!parseFile())
        return -3
    
    return 0; // success 
}
```
- To avoid magic numbers we can use enumeration:
```cpp
enum FileReadResult 
{
    readResultSuccess,
    readResultErrorFileOpen,
    readResultErrorFileRead,
    readResultErrorFileParse,
};

FileReadResult readFileContents()
{
    if(!openFile())
        return readResultErrorFileOpen
    if(!readFile())
        return readResultErrorFileRead 
    if(!parseFile())
        return readResultErrorFileParse
    
    return readResultSuccess; // success 
}
```

- Unscoped enumerations are named as such because they put their enumerator names into the same scope as the enumeration definition 
itself.

```cpp
enum Color
{
    red,
    blue,
    green,
};

enum Feeling
{
    happy,
    tired,
    blue, // error: naming collision with the above blue
};
```
- In the above example both unscoped enumerations (Color and Feeling) put enumerators in global scope with the same name `blue`. This 
leads to a naming collision and causes a compile error.


To avoid naming collision one way is to prefix the enumerators with the name of the enumeration itself:

```cpp
enum Color
{
    color_red,
    color_blue,
    color_green,
};

enum Feeling
{
    feeling_happy,
    feeling_tired,
    feeling_blue,
};

int main()
{
    Color paint { color_blue };
    Feeling me { feeling_blue };

    return 0;
}
```
- This still pollutes the namespace but reduces the chance of naming collisions by making the names longer and more unique.

- A better option is to put enumerated type inside something that provides a separate scope region, such as a namespace:

```cpp 
namespace Color
{
    enum Color
    {
        red,
        green,
        blue,
    };
}
namespace Feeling 
{
    enum Feeling 
    {
        happy,
        tired,
        blue,
    };
}

int main()
{
    Color::Color paint{ Color::blue };
    Feeling::Feeling me { Feeling::blue };

    return 0;
}
```

- Value initialising an enumeration 
```cpp 
#include <iostream>

enum Animal
{
    cat = -3,           // -3
    dog,                // -2
    pig,                // -1
    // no zero in this enumeration 
    horse = 5,          // 5
    giraffe = 5,        // 5
    chicken,            // 6
};

int main()
{
    Animal a{}; // value-initialisation zero-initialises a to value 0
    std::cout << a; // prints 0

    return 0;
}
```

```cpp 
enum Winner 
{
    winnerUnknown, // default value (0)
    player1,
    player2,
};
// somewhere later in the code 
if(w == winnerUnknown) // handle case appropriately
```

- Make the enumeration representing 0 the one that is the best default meaning for your enumeration. If no good default meaning exists,
consider adding an "invalid" or "unknown" enumerator that has value 0, so the state is explicitly documented and can be explicitly handled when appropriate.

- Enumeration can have an underlying type, this should be an integral type.

- Integral to unscoped enumerator conversion, it will not implicitly convert an integer to an unscoped enumeration:
```cpp 
enum Pet
{
    cat,
    dog,
    pig,
    whale,
};

int main()
{
    Pet pet { 2 }; // compile error: integer value 2 won't implicitly convert to a Pet 
    pet = 3        // compile error: integer value 3 won't implicitly convert to a Pet 

    return 0;
}
```

```cpp 
enum Pet
{
    cat,
    dog,
    pig,
    whale,
};

int main()
{
    Pet pet { static_cast<Pet>(2) }; 
    pet = static_cast<Pet>(3);

    return 0;
}
```

## Scope enumerations 
- Two differences: They won't implicitly convert to integers, and the enumerators are only placed into the scope region of the enumeration.

