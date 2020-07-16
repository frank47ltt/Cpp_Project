/************************************
 * Name: Frank Liu (Tongtong)
 * Project: CSC112 Lab 1 Part 1
 * Date: Jan 26, 2020
 ***********************************/

#include <iostream>
#include <string>
#include <vector>
#include <ctime>

using namespace std;

int main() {
    // a brief introduction
    cout << "We are now playing the Battleship game!!!" << endl;
    cout << "Let's get started!" << endl;

    //declare necessary variables for the program
    int row = 3;    // dimension of the matrix
    int col = 3;
    int userRow;    // store user input
    int userCol;
    int shipRow;    // store the random location of the ship
    int shipCol;
    int i;          // used for for loop iteration
    int j;
    int numGuess = 0;   // keep track of the number of guesses

    //declare two 2D vectors
    vector<string> column(col);
    vector<vector<string>> board(row, column);   // keep track of the board template
    vector<vector<string>> user(row, column);    // keep track of user guesses

    // store the exclamation symbol in the template vector
    for (i = 0; i < row; i++) {
        for (j = 0; j < col - 1; j++) {   // do not store ! in the last column
            board.at(i).at(j) = " !";
        }
    }

    // generate random ship location in the range of 1-3
    srand(time(0));
    shipRow = rand() % 3 + 1;
    shipCol = rand() % 3 + 1;

    // print the white board
    cout << "The screen look like this!" << endl;
    for (i = 0; i < row; i++) {
        for (j = 0; j < col; j++) {
            cout << user.at(i).at(j);
            cout << board.at(i).at(j);
        }
        cout << endl;
        if (i != 2) {
            cout << "~~~~~" << endl;
        }
    }

    // ask user input for guessing
    cout << "Please enter the row that you guess where is the ship" << endl;
    cin >> userRow;
    cout << "Please enter the column that you guess where is the ship" << endl;
    cin >> userCol;

    //this while loop is for wrong guessing
    while ((userRow != shipRow) || (userCol != shipCol)) {
        // out-of-range error checking
        if ((userRow < 1) || (userCol < 1) || (userRow > 3) || (userCol > 3)) {
            cout << "Location (row[1-3] column[1-3]): " << userRow << " " << userCol << endl;
            for (i = 0; i < row; i++) {
                for (j = 0; j < col; j++) {
                    cout << user.at(i).at(j);   // print the board
                    cout << board.at(i).at(j);
                }
                cout << endl;
                if (i != 2) {
                    cout << "~~~~~" << endl;
                }
            }
            cout << "Invalid position!" << endl;
            // increment guesses for invalid range
            numGuess++;
            cout << "Please enter the row and column again" << endl;
            // ask for user input again
            cin >> userRow;
            cin >> userCol;
        }

            // enter this when user input within the range but with an incorrect guess
        else {
            cout << "Location (row[1-3] column[1-3]): " << userRow << " " << userCol << endl;
            // store string X in the location of user input to indicate that is a wrong location
            user.at(userRow - 1).at(userCol - 1) = "X";
            // delete the white space before ! to fill it with X except the last column
            if (userCol != 3) {
                board.at(userRow - 1).at(userCol - 1) = "!";
            }

            // print the board with the wrong location indicated as X
            for (i = 0; i < row; i++) {
                for (j = 0; j < col; j++) {
                    cout << user.at(i).at(j);
                    cout << board.at(i).at(j);
                }
                cout << endl;
                if (i != 2) {
                    cout << "~~~~~" << endl;
                }
            }
            // increment number of guesses
            numGuess++;
            cout << "Please enter the row and column again" << endl;
            // ask for user input again
            cin >> userRow;
            cin >> userCol;
        }
    }

    // the program breaks out of the above while loop when user enter
    // correct location and runs into the following code
    cout << "Location (row[1-3] column[1-3]): " << userRow << " " << userCol << endl;
    //using O to indicate the correct position
    user.at(userRow - 1).at(userCol - 1) = "O";
    // delete the white space before ! to fill it with O except the last column
    if (userCol != 3) {
        board.at(userRow - 1).at(userCol - 1) = "!";
    }
    // print the board with previous user guesses and the correct guesses
    for (i = 0; i < row; i++) {
        for (j = 0; j < col; j++) {
            cout << user.at(i).at(j);
            cout << board.at(i).at(j);
        }
        cout << endl;
        if (i != 2) {
            cout << "~~~~~" << endl;
        }
    }
    // increment guesses
    numGuess++;
    // print out final statement with number of guesses
    cout << "You sunk my battleship! (" << numGuess << "  guesses)";
    return 0;
}