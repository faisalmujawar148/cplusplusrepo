#include <iostream>
#include <string>

void printValue (std::string& y)
{
    std::cout << y << '\n';
} // y is destroyed here

int main()
{
    std::string word { "Hello World" };
    
    printValue(word); // it is passed by reference into reference parameter y (inexpensive)
 
    return 0;
}
