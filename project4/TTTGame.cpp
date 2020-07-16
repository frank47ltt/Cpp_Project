/******************************************************************
 * Class: TicTacToe
 * Author: Frank (Tongtong) Liu
 * Description: A program that implements the game Tic-Tac-Toe
 * Date: Feb 22.2020
 ***************************************************************/

#include <iostream>
#include <ctime>
#include "TicTacToe.h"
using namespace std;

int main() {
    // initialize variables
    int numPlayer;
    int whoPlaysFirst;
    int playerPosRow;
    int playerPosCol;
    // declare the object using default constructor to start the game
    TicTacToe game;
    // use seed to help computer generate random number
    srand(time(0));
    // ask if it is a one player game or two players game
    cout << "One-player or Two-player (1 or 2): " << endl;
    cin >> numPlayer;

    // only one player is playing
    if (numPlayer == 1) {
        // determine who will go first
        whoPlaysFirst = rand() % 2;
        if (whoPlaysFirst == 0) {
            cout << "YOU will go first!" << endl;
        } else {
            cout << "Oops, the COMPUTER will go first" << endl;
            // change player to let computer goes first since computer is always the second player
            game.changePlayer();

        }
    }
        // situations when two players are playing
    else {
        cout << "Game Start! Two people will take turn placing the mark!" << endl;
    }
    // start the game
    game.printBoard();
    // enter the while loop until someone win or the board is full
    while (game.isBoardFull() == false && game.checkForWin() == false) {
        // situations where there's one player and one computer, with computer goes first
        if (game.getCurrentPlayerNumber() == 2 && numPlayer == 1) {
            cout << "Player 2(Computer): Enter row and column: " << endl;
            // make sure the position is not out of range and is empty
            while (game.placeMark(rand() % 3, rand() % 3) == false) {
                cout << "The computer will regenerate a position that is empty" << endl;
            }
            // switch player
            game.printBoard();
            game.changePlayer();
            // check for full or win in the middle in case first player wins
            if (game.checkForWin() == true || game.isBoardFull() == true) {
                break;
            }
            cout << "Player 1 (Player): Enter row and column" << endl;
            cin >> playerPosRow;
            cin >> playerPosCol;
            // make sure the position is not out of range and is empty or board is full
            while (game.placeMark(playerPosRow - 1, playerPosCol - 1) == false) {
                cout << "Please re-enter a row and column" << endl;
                cin >> playerPosRow;
                cin >> playerPosCol;
            }
            // switch player
            game.printBoard();
            game.changePlayer();
            // check wins or draw will be done by the while loop
        }
            // situations where there's one player and one computer, with player goes first
        else if (game.getCurrentPlayerNumber() == 1 && numPlayer == 1) {
            cout << "Player 1 (Player): Enter row and column" << endl;
            cin >> playerPosRow;
            cin >> playerPosCol;
            // make sure the position is not out of range and is empty
            while (game.placeMark(playerPosRow - 1, playerPosCol - 1) == false) {
                cout << "Please re-enter a row and column" << endl;
                cin >> playerPosRow;
                cin >> playerPosCol;
            }
            // check players
            game.printBoard();
            game.changePlayer();
            // check for full or win in the middle in case first player wins or board is full
            if (game.checkForWin() == true || game.isBoardFull() == true) {
                break;
            }
            cout << "Player 2 (Computer): Enter row and column" << endl;
            // make sure the position is not out of range and is empty
            while (game.placeMark(rand() % 3, rand() % 3) == false) {
                cout << "The computer will regenerate a position that is empty" << endl;
            }
            // switch player
            game.printBoard();
            game.changePlayer();
            // check wins or draw will be done by the while loop
        }
            // situations where two players take turn plays the game
        else {
            cout << "Player 1: Enter row and column" << endl;
            cin >> playerPosRow;
            cin >> playerPosCol;
            // make sure the position is not out of range and is empty
            while (game.placeMark(playerPosRow - 1, playerPosCol - 1) == false) {
                cout << "Please re-enter a row and column" << endl;
                cin >> playerPosRow;
                cin >> playerPosCol;
            }
            // switch player
            game.printBoard();
            game.changePlayer();
            // check for full or win in the middle in case first player win or board is full
            if (game.checkForWin() == true || game.isBoardFull() == true) {
                break;
            }

            cout << "Player 2: Enter row and column" << endl;
            cin >> playerPosRow;
            cin >> playerPosCol;
            // make sure the position is not out of range and is empty
            while (game.placeMark(playerPosRow - 1, playerPosCol - 1) == false) {
                cout << "Please re-enter a row and column" << endl;
                cin >> playerPosRow;
                cin >> playerPosCol;
            }
            // switch player
            game.printBoard();
            game.changePlayer();
            // check wins or draw will be done by the while loop
        }
    }
    // first check for win since there might be situations when the the board have only one
    // position left and someone will win the game
    // winning has priority over full
    if (game.checkForWin()) {
        // since after placing the mark, there'll be a change player, it's actually player 1 win when playerNum is 2
        if (game.getCurrentPlayerNumber() == 2) {
            cout << "Player 1 wins the game!" << endl;
        } else {
            cout << "Player 2 wins the game!" << endl;
        }

    }
        // then check for draw
    else {
        cout << "This game is a draw!" << endl;
    }
    // end of the program
    return 0;
}