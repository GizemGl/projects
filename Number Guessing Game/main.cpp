#include <iostream>
#include <random>
#include <chrono>

int main()
{

    // This is a number guessing game.
    std::cout << "Welcome to the number guessing game!\n";

    int guess{0};
    int count{0}; // attempt count

    // generate random number between 1-100
    std::mt19937 mt{static_cast<std::mt19937::result_type>(std::chrono::steady_clock::now().time_since_epoch().count())};
    std::uniform_int_distribution randDist{1, 100};
    int num = randDist(mt);

    // ask for player's guess
    while (num != guess)
    {
        std::cout << "Enter your guess (1-100): \n";
        std::cin >> guess;

        if (guess > 100 || guess < 1)
        {
            std::cout << "Invalid guess.\n";
        }

        else
        {

            if (guess > num)
            {
                std::cout << "Too high! Try again.\n";
            }
            if (guess < num)
            {
                std::cout << "Too low! Try again.\n";
            }
            count++;
        }
    }

    std::cout << "Correct! You found the correct number in " << count << " tries.\n";

    return 0;
}
