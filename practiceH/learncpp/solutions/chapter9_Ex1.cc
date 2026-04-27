#include <cstdlib>
#include <ios>
#include <iostream>
#include <limits>
#include <tuple>


void ignoreLine()
{
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

bool hasUnextractedInput()
{
    return !std::cin.eof() && std::cin.peek() != '\n';
}

// returns true if extraction failed, false otherwise
bool clearFailedExtraction()
{
    // check for failed extraction
    if(!std::cin) // if the previous extraction failed
    {
        if(std::cin.eof()) // if the user entered an EOF
        {
            std::exit(0);  // shut the program down
        }
        // lets handle the failure
        std::cin.clear(); // Put us back in normal operation mode
        ignoreLine();     // And remove the bad input

        return true;
    }
    return false;
}

double getDouble()
{
    while(true)
    {
        std::cout << "Enter a decimal number: ";
        double x{};
        std::cin >> x;

        if(clearFailedExtraction())
        {
            std::cout << "The input is invalid try again" << '\n';
            continue;
        }

        ignoreLine(); // Remove any extraneous input 
        return x;
    }
}

char getOperator()
{
    while(true){
        std::cout << "Enter one of the following: +, -, *, or /: ";
        char op{};
        std::cin >> op;

        if(!clearFailedExtraction()) // we'll handle error in the switch
            ignoreLine();            // remove any extraneous input (if extraction succeeded)

        switch(op){
            case '+':
            case '-':
            case '*':
            case '/':
                return op;
            default:
                std::cout << "Oops input is invalid please try again \n";
        }
    }
}

void printResult(double x, char operation, double y)
{
    std::cout << x << ' ' << operation << ' ' << y << " is ";

    switch (operation)
    {
    case '+':
        std::cout << x + y << '\n';
        return;
    case '-':
        std::cout << x - y << '\n';
        return;
    case '*':
        std::cout << x * y << '\n';
        return;
    case '/':
        std::cout << x / y << '\n';
        return;
    }
}

int main()
{
    double x{ getDouble() };
    char operation{ getOperator() };
    double y{ getDouble() };

    while(operation == '/' && y == 0.0)
    {
        std::cout << "The denominator cannot be zero. Try again \n";
        y = getDouble();
    }

    printResult(x, operation, y);

    return 0;
}
