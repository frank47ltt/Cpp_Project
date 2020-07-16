/*************************
 * author: Frank Liu (Tongtong)
 * class: CSC112
 * date: Mar 26
 * project: project 5
 *************************/
#ifndef BLINDMANSBLUFF_CARD_H
#define BLINDMANSBLUFF_CARD_H
#include <string>
#include <iostream>
using namespace std;

// ranks are ordered Ace-low and Queen-high
const string ranks[] = {"Ace","2","3","4","5","6","7","8","9","10","Jack","King","Queen"};
// suits are ordered alphabetically
const string suits[] = {"Clubs","Diamonds","Hearts","Spades"};

class Card {

public:
    // default constructor
    Card();

    // general constructor
    Card(string userRanks, string userSuits);

    // member function to return string
    string printCard() const;

    // overloaded comparison operator
    bool operator<(const Card &rhs);

    // overloaded comparison operator
    bool operator>(const Card &rhs);

    friend class Deck;


private:
    // private data members
    string cardRanks;
    string cardSuits;


};


#endif //BLINDMANSBLUFF_CARD_H
