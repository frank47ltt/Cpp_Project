/* Class: TicTacToe
 * Author: Samuel Cho
 * Description: A class for implementing the game Tic-Tac-Toe
 */

#include <iostream>
#include "TicTacToe.h"
using namespace std;

/* Class: TicTacToe
 * Author: Samuel Cho
 * Description: A class for implementing the game Tic-Tac-Toe
 */

// Constructor for initializing Tic-Tac-Toe game
TicTacToe::TicTacToe() {
    currentPlayerMark = 'x';
    currentPlayerNumber = 1;
    initializeBoard();
}

// Destructor for Tic-Tac-Toe game
TicTacToe::~TicTacToe() { }

// Set (or reset) the board so every position is empty.
void TicTacToe::initializeBoard() {

    // Loop through rows
    for (int i = 0; i < 3; i++) {

        // Loop through columns
        for (int j = 0; j < 3; j++) {
            board[i][j] = '-'; // mark as empty with '-'
        }
    }
}


// Print the current board
void TicTacToe::printBoard() const {
    cout << "-------------" << endl;

    for (int i = 0; i < 3; i++) {
        cout << "| ";
        for (int j = 0; j < 3; j++) {
            cout << board[i][j] << " | ";
        }
        cout << endl;
        cout << "-------------" << endl;
    }
}


// Loop through all positions of the board and check if empty position
// (contains char '-') is found then return false.
// Otherwise the board is full then return true.
bool TicTacToe::isBoardFull() {
    bool isFull = true;

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == '-') {
                isFull = false;
            }
        }
    }
    return isFull;
}


// Returns true if there is a win, false otherwise.
// This calls our other win check functions to check the entire board.
bool TicTacToe::checkForWin() const {
    return (checkRowsForWin() || checkColumnsForWin() || checkDiagonalsForWin());
}


// Loop through each row and see if any are winners.
bool TicTacToe::checkRowsForWin() const {
    for (int i = 0; i < 3; i++) {
        if (checkRowCol(board[i][0], board[i][1], board[i][2]) == true) {
            return true;
        }
    }
    return false;
}


// Loop through each columns and see if any are winners.
bool TicTacToe::checkColumnsForWin() const {
    for (int i = 0; i < 3; i++) {
        if (checkRowCol(board[0][i], board[1][i], board[2][i]) == true) {
            return true;
        }
    }
    return false;
}


// Check the two diagonals to see if either is a winner.
bool TicTacToe::checkDiagonalsForWin() const {
    return ((checkRowCol(board[0][0], board[1][1], board[2][2]) == true)
            || (checkRowCol(board[0][2], board[1][1], board[2][0]) == true));
}


// Check to see if all three values are the same (and not empty) indicating a win.
bool TicTacToe::checkRowCol(char c1, char c2, char c3) const {
    return ((c1 != '-') && (c1 == c2) && (c2 == c3));
}

// Returns current player number
int TicTacToe::getCurrentPlayerNumber() const {
    return(currentPlayerNumber);
}

// Change player marks and number back and forth.
void TicTacToe::changePlayer() {
    if (currentPlayerMark == 'x') { // Player 1
        // Switch to Player 2
        currentPlayerMark = 'o';
        currentPlayerNumber = 2;
    } else { // Player 2
        // Switch to Player 1
        currentPlayerMark = 'x';
        currentPlayerNumber = 1;
    }
}


// Places a mark at the cell specified by row and col with the mark of the current player.
bool TicTacToe::placeMark(int row, int col) {

    // Make sure that row and column are in bounds of the board.
    if ((row >= 0) && (row < 3)) {
        if ((col >= 0) && (col < 3)) {
            if (board[row][col] == '-') {
                board[row][col] = currentPlayerMark;
                return true;
            }
        }
    }
    return false;
}
