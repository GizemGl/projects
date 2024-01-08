#include <iostream>
#include<cstdlib>

int main(){

//This is a number guessing game.
std::cout << "Welcome to the number guessing game!" <<std::endl;

int num; //is the random number.
int g; //guess
int count; //attempt count(max 5)

//generate random number between 1-100
srand((unsigned) time(NULL));
num = 1+(rand()%100);

//ask for player's guess
while (num != g){
    std::cout << "Enter your guess (1-100):" <<std::endl;
    std::cin >> g;
    if (g>num){
        std::cout << "Too high! Try again." <<std::endl;
    }
    if(g<num){
        std::cout << "Too low! Try again." <<std::endl;
    }
    count++;
}

std::cout << "Correct! You found the correct number in " << count <<" tries." <<std::endl;


return 0;
}
