/* Class: TicTacToe
 * Author: Samuel Cho
 * Description: A class for implementing the game Tic-Tac-Toe
 */

#ifndef TICTACTOE_H
#define TICTACTOE_H

class TicTacToe {
private:
    char board[3][3];
    char currentPlayerMark;
    int currentPlayerNumber;

    // Loop through each row and see if any are winners.
    bool checkRowsForWin() const;

    // Loop through each columns and see if any are winners.
    bool checkColumnsForWin() const;

    // Check the two diagonals to see if either is a winner.
    bool checkDiagonalsForWin() const;

    // Check to see if all three values are the same (and not empty) indicating a win.
    bool checkRowCol(char c1, char c2, char c3) const;

public:
    // Constructor for initializing Tic-Tac-Toe game
    TicTacToe();

    // Destructor for Tic-Tac-Toe game
    ~TicTacToe();

    // Set (or reset) the board so every position is empty.
    void initializeBoard();

    // Print the current board
    void printBoard() const;

    // Loop through all positions of the board and check if empty position
    // (contains char '-') is found then return false.
    // Otherwise the board is full then return true.
    bool isBoardFull();

    // Returns true if there is a win, false otherwise.
    // This calls our other win check functions to check the entire board.
    bool checkForWin() const;

    // Returns current player number
    int getCurrentPlayerNumber() const;

    // Change player marks and number back and forth.
    void changePlayer();

    // Places a mark at the cell specified by row and col with the mark of the current player.
    bool placeMark(int row, int col);
};

#endif //TICTCTOE_H
