/*************************
 * author: Frank Liu (Tongtong)
 * class: CSC112
 * date: Mar 26
 * project: project 5
 *************************/
#ifndef BLINDMANSBLUFF_DECK_H
#define BLINDMANSBLUFF_DECK_H

#include "Card.h"

class Deck {
public:
    // Constructor
    Deck();

    // Overload Constructor
    Deck(int a, int b);

    // Destructor
    ~Deck();

    // Copy Constructor
    Deck(const Deck &origDeck);

    // Copy Assignment Operator
    Deck &operator=(Deck &rhs);

    // Populate the Deck with 52 cards member function
    void populateCards();

    // member function to shuffle card
    void shuffle();

    // remove cards
    Card removeCard(int index);


    // member function to add card
    bool addCard(Card &addCard);

    // debugging helper functions
    int getCardsLeft();

    void printDeck();


private:
    // pointers to array of cards
    Card *cards;
    // physical size --- maximum size
    int arraySize;
    // logical size --- current size
    int cardsLeft;
};


#endif //BLINDMANSBLUFF_DECK_H
