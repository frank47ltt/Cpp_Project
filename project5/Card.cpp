/*************************
 * author: Frank Liu (Tongtong)
 * class: CSC112
 * date: Mar 26
 * project: project 5
 *************************/
#include "Card.h"
#include <string>
#include <iostream>
#include <sstream>

using namespace std;

//default constructor
Card::Card() {
    cardRanks = "unknown";
    cardSuits = "unknown";
}

// general constructor
Card::Card(string userRanks, string userSuits) {
    cardRanks = userRanks;
    cardSuits = userSuits;
}

// member function that returns a string of value of cards
// utilizing output string stream
string Card::printCard() const {
    ostringstream infoOSS;
    infoOSS << cardRanks << " of " << cardSuits << endl;
    return infoOSS.str();
}

// overloaded comparison operator
bool Card::operator<(const Card &rhs) {
    // I need to compare the index since the member variable are strings
    int indexRanksLeft;
    int indexRanksRight;
    int indexSuitsLeft;
    int indexSuitsRight;

    // iterate through the array to find matched ranks and suits
    for (int i = 0; i < 13; i++) {
        if (this->cardRanks == ranks[i]) {
            indexRanksLeft = i;
        }
        if (rhs.cardRanks == ranks[i]) {
            indexRanksRight = i;
        }
    }

    for (int i = 0; i < 4; i++) {
        if (this->cardSuits == suits[i]) {
            indexSuitsLeft = i;
        }
        if (rhs.cardSuits == suits[i]) {
            indexSuitsRight = i;
        }
    }

    // situations where rank of lfs is less than rank of rhs
    if (indexRanksLeft < indexRanksRight) {
        return true;
    }
        // situations where rank of lfs is equal to rank of rhs
        // compare suits
    else if (indexRanksLeft == indexRanksRight) {
        if (indexSuitsLeft < indexSuitsRight) {
            return true;
        } else {
            return false;
        }
    }
        // situations where rank of lfs is greater than rank of rhs
    else {
        return false;
    }
}


bool Card::operator>(const Card &rhs) {
    // I need to compare the index since the member variable are strings
    int indexRanksLeft;
    int indexRanksRight;
    int indexSuitsLeft;
    int indexSuitsRight;

    // iterate through the array to find matched ranks and suits
    for (int i = 0; i < 13; i++) {
        if (this->cardRanks == ranks[i]) {
            indexRanksLeft = i;
        }
        if (rhs.cardRanks == ranks[i]) {
            indexRanksRight = i;
        }
    }

    for (int i = 0; i < 4; i++) {
        if (this->cardSuits == suits[i]) {
            indexSuitsLeft = i;
        }
        if (rhs.cardSuits == suits[i]) {
            indexSuitsRight = i;
        }
    }

    // situations where rank of lfs is less than rank of rhs
    if (indexRanksLeft < indexRanksRight) {
        return false;
    }
        // situations where rank of lfs is equal to rank of rhs
        // compare suits
    else if (indexRanksLeft == indexRanksRight) {
        if (indexSuitsLeft < indexSuitsRight) {
            return false;
        } else {
            return true;
        }
    }
        // situations where rank of lfs is greater than rank of rhs
    else {
        return true;
    }
}
