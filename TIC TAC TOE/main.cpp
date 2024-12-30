#include <iostream>
#include <vector>
#include <limits>

using namespace std;

// Display the current board state
void displayBoard(const vector<vector<char>> &board) {
    cout << "  0 1 2\n"; // Column indices
    for (int i = 0; i < board.size(); ++i) {
        cout << i << " "; // Row index
        for (int j = 0; j < board[i].size(); ++j) {
            cout << board[i][j];
            if (j < board[i].size() - 1) cout << "|";
        }
        cout << endl;
        if (i < board.size() - 1) cout << "  -----\n";
    }
}

// Check if there is a winner
bool checkWin(const vector<vector<char>> &board, char player) {
    // Check rows, columns, and diagonals
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player) return true; // Row
        if (board[0][i] == player && board[1][i] == player && board[2][i] == player) return true; // Column
    }
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player) return true;     // Diagonal
    if (board[0][2] == player && board[1][1] == player && board[2][0] == player) return true;     // Anti-diagonal

    return false;
}

// Check if the board is full (draw)
bool isDraw(const vector<vector<char>> &board) {
    for (const auto &row : board) {
        for (const auto &cell : row) {
            if (cell == '-') return false;
        }
    }
    return true;
}

// Main game function
int main() {
    vector<vector<char>> board(3, vector<char>(3, '-')); // Initialize 3x3 board
    char currentPlayer = 'X'; // Start with player X
    int row, col;

    cout << "Welcome to Tic-Tac-Toe!\n";
    displayBoard(board);

    while (true) {
        cout << "Player " << currentPlayer << ", enter your move (row and column): ";

        // Input validation
        if (!(cin >> row >> col)) {
            cout << "Invalid input! Please enter integers for row and column.\n";
            cin.clear(); // Clear the error flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore the invalid input
            continue;
        }

        // Validate move
        if (row < 0 || row >= 3 || col < 0 || col >= 3 || board[row][col] != '-') {
            cout << "Invalid move! Try again.\n";
            continue;
        }

        // Make the move
        board[row][col] = currentPlayer;
        displayBoard(board);

        // Check for win or draw
        if (checkWin(board, currentPlayer)) {
            cout << "Player " << currentPlayer << " wins!\n";
            break;
        }

        if (isDraw(board)) {
            cout << "It's a draw!\n";
            break;
        }

        // Switch player
        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
    }

    cout << "Game Over. Thanks for playing!\n";
    return 0;
}
