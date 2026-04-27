#include <iostream>
#include <string>
#include <string_view>

void printSV(std::string_view sv)
{
    std::cout << sv << '\n';
}

void printS(const std::string& s)
{
    std::cout << s << '\n';
}

int main()
{
    std::string s {"Hello world!"};
    std::string_view sv { s };

    printSV(sv);
    printSV(s);
    printSV("Hello, world");
    
    printS(s);
    printS(static_cast<std::string>(sv));
    printS("Hello World");

    return 0;
}
