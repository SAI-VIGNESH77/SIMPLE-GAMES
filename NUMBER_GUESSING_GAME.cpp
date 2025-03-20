#include <iostream>
#include <cstdlib>
#include <ctime>

void playGame() {
    std::srand(static_cast<unsigned int>(std::time(nullptr))); // Seed the random number generator
    int secretNumber = std::rand() % 100 + 1; // Random number between 1 and 100
    int guess = 0, attempts = 0;

    std::cout << "🎉 Welcome to the Number Guessing Game! 🎉\n";
    std::cout << "I've picked a number between 1 and 100. Can you guess it?\n";

    while (true) {
        std::cout << "\nEnter your guess: ";
        std::cin >> guess;
        attempts++;

        if (std::cin.fail()) { // Handling invalid input
            std::cin.clear(); 
            std::cin.ignore(10000, '\n'); 
            std::cout << "Oops! That doesn't look like a number. Try again!\n";
            continue;
        }

        if (guess < 1 || guess > 100) {
            std::cout << "Hey, stick to the rules! Pick a number between 1 and 100.\n";
            continue;
        }

        if (guess > secretNumber) {
            std::cout << "Too high! Try something lower. 🔽\n";
        } else if (guess < secretNumber) {
            std::cout << "Too low! Aim a little higher. 🔼\n";
        } else {
            std::cout << "🎯 Bingo! You guessed it in " << attempts << " attempts.\n";
            if (attempts <= 5) {
                std::cout << "You're a natural! 🏆\n";
            } else if (attempts <= 10) {
                std::cout << "Good job! That was a solid effort. 👍\n";
            } else {
                std::cout << "Phew! That took some time, but you made it! 🎊\n";
            }
            break;
        }
    }
}

int main() {
    char choice;
    do {
        playGame();
        std::cout << "\nWant to play again? (y/n): ";
        std::cin >> choice;
    } while (choice == 'y' || choice == 'Y');

    std::cout << "Thanks for playing! See you next time. 👋\n";
    return 0;
}
