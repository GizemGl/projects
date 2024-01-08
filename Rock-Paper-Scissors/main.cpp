//Rock-Paper-Scissors game
#include <iostream>
#include <ctime>


char getUserInput();
char getCompInput();
void showValue(char x);
void getWinner(char x, char y);
int getScore(char x, char y);


int main(){

//ask how many matches user wants to play
int matches;
std::cout << "How many games do you want to play?:" <<std::endl;
std::cin >> matches;

while(matches<1){
std::cout << "Please enter a valid number." <<std::endl;
std::cout << "How many games do you want to play?:" <<std::endl;
std::cin >> matches;
}

int countmatches=0;
int score=0;
while(countmatches<matches){
char player = getUserInput();
std::cout << "You chose: ";
showValue(player);
char comp = getCompInput();
std::cout << "Computer chose: ";
showValue(comp);
getWinner(player, comp);
score= score+getScore(player,comp);
countmatches++;
}

std::cout << matches << " matches played in total." << std::endl;


if(score<0){
    std::cout << "YOU LOST THE GAME!" << std::endl;
}
else if (score==0){
    std::cout << "IT'S A TIE!" << std::endl;
}
else{
    std::cout << "YOU WON THE GAME!" << std::endl;
}

    return 0;
}

//ask user choice

char getUserInput(){
    char userInput;
    std::cout << "Rock, paper or scissors? (r-p-s):" << std::endl;
    std::cin >> userInput;
    if (userInput != 'r' && userInput != 'p' && userInput != 's'){
        std::cout << "Please enter a valid character." << std::endl;
        std::cout << "Rock, paper or scissors? (r-p-s):" << std::endl;
        std::cin >> userInput;
    }
    return userInput;
}

//generate computer's choice
char getCompInput(){
    srand(time(NULL));
    int r = rand()%3 + 1;
    
    switch(r){
        case 1: return 'r';
        break;
        case 2: return 'p';
        break;
        case 3: return 's';
        break;
    }

    return 0;
}

//show value
void showValue(char x){
    switch(x){
        case 'r': std::cout << "Rock" << std::endl;
        break;
        case 'p': std::cout << "Paper" << std::endl;
        break;
        case 's': std::cout << "Scissors" << std::endl;
        break;
    }
}

//pick winner
void getWinner(char x, char y){
    if((x=='r' && y=='p') || (x=='p' && y=='s') || (x=='s' && y=='r')){
        std::cout << "YOU LOST!" << std::endl;
    } 
    else if (x==y){
        std::cout << "IT'S A TIE!" << std::endl;
    }
    else{
        std::cout << "YOU WON!" << std::endl;
    }
}

//count score
int getScore(char x, char y){
    if((x=='r' && y=='p') || (x=='p' && y=='s') || (x=='s' && y=='r')){
        return -1;
    } 
    else if (x==y){
        return 0;
    }
    else{
        return 1;
    }
}




