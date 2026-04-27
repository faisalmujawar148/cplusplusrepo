#include <iostream>

int main()
{
    short bombs { 1 };

    const int& you { bombs };
    --bombs;

    if (you)
        std::cout << "Bombs away!, Goodbye, cruel world.\n";


    return 0;
}

/*
* Normally we assume that the reference is identical to the object, this assumption is broken when a reference is bound
* to a temporary copy of the object or a temporary resulting from the conversion of the object instead. Any modification
* made to the object will not be seen by the reference, and vice-versa. 
*/
