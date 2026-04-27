#include <iostream>
#include <string>

const std::string& firstAlphabetical(std::string& s1, std::string& s2)
{
    return (s1 < s2) ? s1 : s2;
}

int main()
{
    std::string hello {"Hello"};
    std::string world {"World"};

    std::cout << firstAlphabetical(hello, world) << '\n';

    return 0;
}
