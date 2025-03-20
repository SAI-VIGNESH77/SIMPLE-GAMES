#include <iostream>
#include <vector>

using namespace std;

vector<char> board = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};
char currentPlayer = 'X';

void displayBoard() {
    cout << "\n";
    for (int i = 0; i < 9; i += 3) {
        cout << " " << board[i] << " | " << board[i + 1] << " | " << board[i + 2] << "\n";
        if (i < 6) cout << "---|---|---\n";
    }
    cout << "\n";
}

bool checkWin() {
    int winPatterns[8][3] = {
        {0, 1, 2}, {3, 4, 5}, {6, 7, 8},  // Rows
        {0, 3, 6}, {1, 4, 7}, {2, 5, 8},  // Columns
        {0, 4, 8}, {2, 4, 6}              // Diagonals
    };

    for (auto &pattern : winPatterns) {
        if (board[pattern[0]] == board[pattern[1]] && board[pattern[1]] == board[pattern[2]]) {
            return true;
        }
    }
    return false;
}

bool isDraw() {
    for (char c : board) {
        if (c >= '1' && c <= '9') return false; // If there's a number, moves are left
    }
    return true;
}

void switchPlayer() {
    currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
}

void playGame() {
    int move;
    while (true) {
        displayBoard();
        cout << "Player " << currentPlayer << ", enter your move (1-9): ";
        cin >> move;

        if (cin.fail() || move < 1 || move > 9 || board[move - 1] == 'X' || board[move - 1] == 'O') {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Invalid move! Try again.\n";
            continue;
        }

        board[move - 1] = currentPlayer;

        if (checkWin()) {
            displayBoard();
            cout << "🎉 Player " << currentPlayer << " wins! 🎉\n";
            break;
        }

        if (isDraw()) {
            displayBoard();
            cout << "It's a draw! 🤝\n";
            break;
        }

        switchPlayer();
    }
}

int main() {
    cout << "Welcome to Tic-Tac-Toe! 🎮\n";
    playGame();
    return 0;
}
