#include <iostream>
#include <random>

namespace Constants {
    constexpr int tries { 7 };
    constexpr int min { 1 };
    constexpr int max { 100 };
}

int getRandom(){
    std::random_device rd;
    std::uniform_int_distribution<int> dist(1, 100);
    
    return dist(rd);
}

void playHiLo( int tries, int min, int max ){
    std::cout << "Lets's play a game. I'm thinking of a number between 1 and 100. You have 7 tries to guess what it is." << '\n';
    const int number { getRandom() };
    for(int i { 0 }; i <=tries; i++){
        std::cout << "Guess #" << i << ": ";

        int guess{};
        std::cin >> guess;

        if(guess > number)
            std::cout << "Your guess is too high" << '\n';
        else if(guess < number)
            std::cout << "Your guess is too low" << '\n';
        else
         std::cout << "Correct, you win!" << '\n';
    }
}

bool playAgain()
{
    while(true){
        char ch{};
        std::cout << "Would you like to play again (y/n)?";
        std::cin >> ch;

        switch (ch){
            case 'y': 
                return true;
            case 'n':
                return false;
        }
    }
}

int main(){

    do { 
     playHiLo(Constants::tries, Constants::min, Constants::max);
    }while(playAgain());

    return 0;
}
