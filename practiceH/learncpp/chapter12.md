# Compound Types: References and Pointers
- Functions are a compound data type:

```c++
void doSomething(int x, double y)
{
}
```

- The type of this function void(int, double) is composed of fundamental types,
making it a compound type.
- All expressions in C++ have two properties: a type and value category.

- The type of an expression is equivalent to the type of the value, object, or function,
that results in the evaluated expression.
- The type of the expression must be determinable at compile time(otherwise type checking and type deduction won't work)
however, the value of an expression may be determined at compile time or runtime.

- The *value category* of an expression indicates whether an expression resolves to a values, a function, or an object of some kind.

- An lvalue is an expression that evaluates to an identifiable object or function. lvalues can be modifiable, **modifiable lvalue**,
or they can be **non-modifiable** lvalue.

- rvalue expressions evaluate to a value. Commonly seen ones are literals and return value of function and operators that return by 
value. Rvalues aren't identifiable (have to used immediately), and only exist within the scope of the expression in which they are used.

- `operator+` expects its operands to be rvalues. The assignment operator required left operand to be an lvalue.

- In cases where rvalue is required but lvalue is provided, the lvalue will undergo an lvalue-to-rvalue conversion.

```c++
int main()
{
    int x{ 1 };
    int y{ 2 };

    x = y; // y is not an rvalue, but this is legal

    return 0;
}
```

- Lvalues expressions are those that evaluate to functions or identifiable objects (including variables) that persists beyond the 
end of the expression.
- Rvalues expressions are those that evaluate to values, including literals and temporary objects that do not persist beyond the end 
of the expression.

## L value references 
- A reference is an alias for an existing object. Once a reference has been defined, any operations on the reference is applied to the object
being referenced

- When defining a reference, place an ampersand next to the type(not the reference variable's name).

- The ampersand in this context does not mean "address of" it means "lvalue reference to"

## Reference initialisation

```c++
int main()
{
    int x{ 5 };
    int& ref{ x }; // okay non const lvalue reference bound to a modifiable Lvalue 
    
    const int y{ 5 }; 
    int& invalidRef{ y }; // invalid non-const lvalue reference can't bind to a non-modifiable lvalue.
    int& invalidRef2{ 0 };// invalid non-const lvalue reference can't bind to an rvalue 
    return 0;
}
```

- A reference will (usually) only bind to an object matching its referenced type 

- lvalue reference can only bind to a modifiable lvalue. Which means the following is illegal:

```c++
int main()
{
    const int x { 5 }; // x is not modifiable lvalue 
    int& ref { x };    // error: ref can not bind to non-modifable lvalue 

    return 0;
}
```

- By using a `const` keyword we can tell an lword reference to treat the reference as const. Such a reference is called an 
**lvalue reference to a const value** (**reference to const** or a **const reference**).

- Favour `lvalue references to const` over `lvalue references to non-const` unless you need to modify the object being referenced. 

```c++
#include <iostream>

int main()
{
    const int& ref{ 5 }; // 5 is an rvalue 
    
    std::cout << ref << '\n'; // prints 5

    return 0;
}
```
- When the above happens a temp object is created and initialised with the rvalue, and the reference to const is bound to that temporary object.

- Lvalues can even bind to a value of a different type as long as it can be implicitly converted to the reference type

- If you try to bind a const lvalue to value of a different type, the compiler will create a temporary object of the same type as the reference,
initialise it using the value, and then bind the reference to the temporary.

Const references bound to temporary objects extend the lifetime of the temporary object: 
- To avoid dangling references, when a const reference is directly bound to a temporary object, the lifetime of the temporary object is extended
to match the lifetime of the reference.

- Lvalue references can only bind to modifiable lvalues 
- Lvalue references to const can bind to modifiable lvalues, non-modifable lvalues, and rvalues. This makes them more flexible type of 
reference.

- constexpr lvalues references can only be applied to globals and static variables.

## Pass by l value reference 

```c++
#include <iostream>
#include <string>

void printValue(std::string y)
{
    std::cout << y << '\n';
}
int main()
{
    std::string x { "Hello World" };
    
    printValue(x); // x is passed by value (copied) into parameter y(expensive)

    return 0;
}
```
- Pass by reference allows us to change the value of an argument
- Passing by reference to non-const lets us write functions that modify the value of the arguments that are passed in.
- Pass by reference can only accept modifiable lvalue arguments.

## Pass by const lvalue reference 
- Unlike a non-const (which can only bind to modifiable lvalues), a reference to a const can bind to modifiable lvalues,
non-modifable lvalues, and rvalues.
- However, we cannot modify the value being referenced.
- Favour passing by const reference over passing by non-const reference unless you need to modify the value of an argument.

## Passing arguments of a different type to a const reference parameter 
- This will result in an expensive copy as we don't want to create copies as we are passing by reference we should avoid doing this.

## Mixing pass by value and pass by Reference
```c++
#include <string>

void foo(int a, int& b, const std::string& c)
{
}

int main()
{
    int x { 5 };
    const std::string s { "Hello, World" };
    
    foo(5, x, s);

    return 0;
}
```
- In the above example, the first argument is pass by value, second is by reference, third is by const reference. 

## When to pass by reference and by value 
- Fundamental data types and enumerated data types are cheap to copy, so they are typically passed by value.
- Class types can be expensive to copy, so they are typically passed by const reference.

The following should be passed by value:
- Enumerated Types 
- Views and spans (e.g. `std::string_view`, `std::span`)
- Types that mimic references or (non-owning) pointers (e.g. iterators, `std::reference_wrapper`)
- Cheap-to-copy class types that have value semantics (e.g. `std::pair` with elements of fundamental types, `std::optional`,
`std::expected`)

Pass by reference:
- Arguments that need to modified by the function 
- Types that aren't copyable (such as `std::ostream`)
- Types where copying has ownership implications that we want to avoid (e.g. `std::unique_ptr`, `std::shared_ptr`)
- Types that have virtual functions or are likely to be inherited from.

## The cost of pass by value vs pass by reference 
- With pass by value initialisation means making a copy. The cost of copying is proportional to two things
    1) The size of the object. Objects with more memory take more time to copy.
    2) Any additional setup costs. Some class types do additional setup when they are instantiated (e.g. such as opening a file or database,
        or allocating a certain amount of dynamic memory to hold an object of a variable size). These setup costs must be paid each time an object is copied.
- Secondly, when setting up a function call, the compiler may be able to optimise by placing a reference or copy of a passed-by-value 
argument (if it's small) in to a CPU register (which is fast to access) rather than into the RAM.
    - Each use of a value parameter is a single CPU register or RAM access, whereas each use of a reference parameter is a single CPU 
    register or RAM access plus a second RAM access.
- Third, the compiler can sometimes optimise code that uses pass by value for effectively than code that uses pass by reference. In 
particular, optimisers have to be conservative when there is a chance for aliasing (when two or more pointers or references can access the same object).
Because pass by value results in the copy of argument values, there is no chance for aliasing to occur, allowing optimisers to be more aggressive.

- We don't pass everything by pass by references as:
    - For objects that are cheap to copy, the cost of copying is similar to the cost of binding, but accessing the objects is faster
    and the compiler is likely able to optimise better.
    - For objects that are expensive to copy, the cost of copying dominates other performance considerations.

## Prefer `std::string_view` over `const std::string&` in most cases 
- If your function needs to call another function that takes a C-style string or `std::string` parameter, then `const std::string&` 
might be a better choice, as `std::string_view` isn't guaranteed to be null terminated (something C-style string functions expect) 
and does not efficiently convert back to an `std::string`.
- Prefer passing strings using `std::string_view` (by value) instead of `const std::string&` unless your function calls other functions 
that require C-style strings or `std::string` parameters.

## Why `std::string_view` parameters are more efficient than `const std::string&`
- In C++ a string argument will be `std::string`, a `std::string_view` or a C-style string literal.

 |  Argument Type          | std::string_view parameter |   const std::string& parameter                  |
 |-------------------------|----------------------------|-------------------------------------------------|
 |  std::string            |  Inexpensive conversion    |   Inexpensive reference binding                 |                                                     
 |-------------------------|----------------------------|-------------------------------------------------|
 |  std::string_view       |  Inexpensive copy          |   Expensive explicit conversion to `std::string`|
 |-------------------------|----------------------------|-------------------------------------------------|
 |  C-style string/literal |  Inexpensive conversion    |   Expensive conversion                          |

- `const std::string&` only handles `std::string` arguments inexpensively. For std::string_view we have to explicitly convert 
the string_view to an `std::string` which expensive. For a C-style string/literal it will implicitly convert to an `std::string`,
which is expensive.



## Pointers 
- Consider a variable `char x {} // chars use 1 byte of memory` when this is code is executed, a piece of memory from RAM will 
be assigned to this object. For example, let's say the variable `x` is assigned memory address `140`. Whenever, we use variable 
`x` in an expression or statement, the program will go to memory address `140` to access the value stored there.

- The address operator returns the memory address of the operand: `&`.
- The dereference operator is `*`. It returns the value at a given memory address as an lvalue.
- A pointer is an object that holds a memory address (typically of another variable) as its value. This allows us to store the address
of some other object to use later.

```c++
int; // normal int 
int& // lvalue reference to an int value 

int* // a pointer to an int value (holds the address of an integer value)
```

To create a pointer variable we can:

```c++
int main()
{
    int x { 5 };       // normal variable 
    int& ref { x };    // a reference to an integer (bound to x)

    int* ptr;          // a pointer to an integer

    return 0;
}
```
## Pointer initialisation 
A pointer that has not been initialised is sometimes called a **wild pointer**. Wild pointers contain garbage memory address, 
and dereferencing a wild pointer will result in undefined behaviour. Because of this, you should always initialise your pointers
to a known value:

```c++
int main()
{
    int x{ 5 };
    int* ptr;       // an uninitialised pointer (holds garbage value)
    int* ptr2{};    // a null pointer 
    int* ptr3{ &x };// a pointer initialised with the address of variable x 

    return 0;
}
```

- The type of the reference has the match the type of the object being referred to, the type of the pointer has to match the type 
of the object being pointed to:

```c++
int main()
{
    int i { 5 };
    double d { 7.0 };

    int* iPtr{ &i };      // ok: a pointer to an int can point to an int object 
    int* iPtr2{ &d };     // not okay: a pointer to an int cannot point to a double object 
    double* dPtr{ &d };   // ok: a pointer to a double can point to a double object 
    double* dPtr2{ &i };  // not okay: a pointer to a double cannot point to an int object 

    return 0;
}
```

```c++
    int* ptr{ 5 }; // not okay
    ptr* ptr{ 0x0012FF7C }; // not okay, 0x0012FF7C is treated as an integer literal
```

## Pointers and assignments 
- We can use assignment in two ways:
1) To change what the pointer is pointing at (by assigning the pointer a new address)
2) To change the value being pointed at (by assigning a dereferenced pointer a new value)

- Modifying i.e. `ptr = &y` changes what the pointer is pointing at. When we dereference the pointer we are accessing the object being 
pointed at i.e. `*ptr = 6` changes the value of the object being pointed at.

## Pointers behave like lvalue reference 
- Reference are required to be initialised, pointers aren't required to be initialised (but should be)
- References are not objects, pointers are 
- References can not be reseated (changed to reference something else), pointers can change what they are pointing at 
- References must always be bound to an object, pointers can point to nothing. 
- References are "safe" (outside of dangling references), pointers are inherently dangerous.

## The address-of operator returns a pointer 
- It returns a pointer to the operand. Given variable `int x`, `&x` returns an `int*` holding the address of `x`.

## Null pointer 
```c++
int main()
{
    int* ptr { nullptr };

    int value { 5 };
    int* ptr2 { &value };
    ptr2 = nullptr; 

    someFunction(nullptr);

    return 0;
}
```

## Pointers and const 
```c++
int main()
{
    const int x { 5 };
    int* ptr  { &x }; // compile error : cannot convert cont int* to int*

    return 0;
}
```

## Pointer to const value 
```c++
int main()
{
    const int x { 5 };    
    const int* ptr { &x };  // okay: ptr is pointing to a "const int"

    *ptr = 6; // not allowed we can't change a const value 

    return 0;
}
```

```c++
int main()
{
    const int x{ 5 };
    const int* ptr { &x }; // ptr points to const int x 

    const int y{ 6 };
    ptr = &y; // okay ptr now points at const int y 

    return 0;
}
```
- Because a pointer to a const isn't const itself (it just points to a const value), we can change its value it's pointing to by assigning 
the pointer a new address.

## Const pointers 
- A const pointer is a pointer that cannot be changed after initialisation. 
```c++
int main()
{
    int x{ 5 };
    int* const ptr { &x }; // const after the asterix means this is a const pointer 

    return 0;
}
```

```c++
int main()
{
    int x{ 5 };
    int y{ 6 };

    int* const ptr { &x };
    ptr = &y; // error: once initialised cannot change the const pointer 

    return 0;
}
```
- However we can still change the value if the value is non-const.
```c++
int main()
{
    int value { 5 };
    int* const ptr { &x };

    *ptr = 6; // This is okay value being pointed to is non-const

    return 0;
}
```

## Const pointer to a const value 
```c++
int main()
{
    int value { 5 };
    const int* const ptr { &value }; // a const pointer to a const value

    return 0;
}
```
- A const pointer to a const value cannot have its address changed, nor can the value it is pointing to can be changed through the pointer. 
It can only be dereferenced to get the value it is pointing at.

## Pass by address 
- Does not make a copy of the variable being passed through.
- Pass by address allows us to modify the arguments value

## Prefer pass by (const) reference 
- Pass by const reference supports modifiable lvalues, const lvalues, and rvalues.

## Pass by address by reference 
- You can also pass pointers by reference:

## Return by reference and return by address 
```c++
std::string& returnByReference(); // return a reference to an existing std::string (cheap)
cont std::string& returnByReferenceConst(); // returns a const reference to an existing std::string (cheap)
```
- Return by reference returns a reference that is bound to the object being returned, which avoids making a copy of the return value.
- The object being returned by reference must exist after the function returns.  

## Don't return non-const static local variables by reference 
- Avoid returning references to non-cost local static variables 

## It's okay to return reference parameters by reference 
- If a parameter is passed into a function by reference, it's safe to return that parameter by reference.
- In order to pass an argument to a function, that argument must exist in the scope of the caller. When the function returns 
the object must still exist in the scope of the caller.


## In parameters 
- In most cases, a function parameter is used only to receive an input from the caller. Parameters that are used only for receiving input 
are sometimes called **in parameters**.

## Out parameters 
- A function parameter that is used only for the purpose of returning information back to the caller is called an **out parameter**.


## std::optional 
- Is a class template that implements an optional value. That is, a `std::optional<T>` can either have a value of type `T` or not.
```c++
std::optional<int> o1 { 5 };            // initialize with a value
std::optional<int> o2 {};               // initialize with no value
std::optional<int> o3 { std::nullopt }; // initialize with no value
```
- To see if `std::optional` has a value we can do the following:
```c++
if(o1.has_value())
if(o2)   // implicit bool conversion to check if o2 has a value
```
- To get a value from `std::optional` we can:
```c++
std::cout << *o1;
std::cout << o2.value()
std::cout << o3.value_or(42); // if o3 doesn't have a value puts a value of 42 in there.
```

- A pointer and `std::optional` are quite different:
    - A pointers has reference semantics, meaning it references some other object, and assignment copies the pointer, not the object.
    If we return a pointer by address, the pointer is copied back to the caller, not the object being pointed to. This means we cannot 
    return a local object by address, as we'll copy that object's address back to the caller, and then the object will be destroyed leaving
    the returned pointer dangling.
    - A `std::optional` has value semantics, meaning it actually contains its value, and assignment copies the value. If we return a `std::optional`
    by value, the `std::optional` is copied back to the caller. This means we can return a value from the function back to the caller using 
    `std::optional`.


- Return an `std::optional` instead of sentinel values for functions that may fail, unless your function needs to return additional information about 
why it failed.



