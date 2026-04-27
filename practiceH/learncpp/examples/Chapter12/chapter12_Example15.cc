#include <iostream>
#include <string>

const std::string& getProgramName() // returns a const reference 
{
    static const std::string s_programName { "Calculator" }; // has static duration, destroyed at the end of the program
    
    return s_programName;
}

int main()
{
    std::cout << "The program is named " << getProgramName();

    return 0;
}

/*
 * In the program above s_programName has static duration, s_programName must exist to the end of the program. When main() accesses
 * the returned reference, it's actually accessing s_programName, which is fine because s_programName won't be destroyed until later.
*/

/*
 * If we remove the static keyword for s_programName we create a dangling reference as programName will have automatic duration and 
 * will only last till the end of the function. This means that the reference is dangling, the use of `programName` in `main()` 
 * results in undefined behaviour
*/
