#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

// Function to get the computer's choice
string getComputerChoice() {
    srand(time(0)); // Seed the random number generator
    int randomChoice = rand() % 3; // Generates 0, 1, or 2

    switch (randomChoice) {
        case 0: return "Rock";
        case 1: return "Paper";
        case 2: return "Scissors";
    }
    return "Rock"; // Fallback (should never happen)
}

// Function to determine the winner
string determineWinner(string player, string computer) {
    if (player == computer) return "It's a tie!";
    if ((player == "Rock" && computer == "Scissors") ||
        (player == "Paper" && computer == "Rock") ||
        (player == "Scissors" && computer == "Paper")) {
        return "You win!";
    }
    return "Computer wins!";
}

int main() {
    string playerChoice;
    
    cout << "Welcome to Rock-Paper-Scissors!\n";
    cout << "Enter Rock, Paper, or Scissors: ";
    cin >> playerChoice;

    // Convert user input to first letter uppercase
    for (char &c : playerChoice) c = tolower(c);
    playerChoice[0] = toupper(playerChoice[0]);

    // Validate input
    if (playerChoice != "Rock" && playerChoice != "Paper" && playerChoice != "Scissors") {
        cout << "Invalid input! Please enter Rock, Paper, or Scissors.\n";
        return 1;
    }

    string computerChoice = getComputerChoice();
    cout << "Computer chose: " << computerChoice << endl;

    cout << determineWinner(playerChoice, computerChoice) << endl;

    return 0;
}
