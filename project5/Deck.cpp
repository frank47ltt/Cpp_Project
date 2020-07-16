/*************************
 * author: Frank Liu (Tongtong)
 * class: CSC112
 * date: Mar 26
 * project: project 5
 *************************/
#include "Deck.h"
#include <cmath>
#include <ctime>
#include <iostream>

using namespace std;

// default constructor
Deck::Deck() {
    cards = new Card[arraySize];
    arraySize = 52;
    cardsLeft = 0;    // initially no cards in the deck
}

// constructor
Deck::Deck(int a, const int b = 52) {
    arraySize = b;
    cardsLeft = a;
}

// The big three
Deck::Deck(const Deck &origDeck) {
    cout << "copy constructor called." << endl;
    arraySize = origDeck.arraySize;
    cardsLeft = origDeck.cardsLeft;
    cards = new Card[arraySize];
    for (int i = 0; i < 52; i++) {
        cards[i] = origDeck.cards[i];
    }
}

Deck &Deck::operator=(Deck &rhs) {
    cout << "Copy assignment operator called" << endl;
    Deck tmp(rhs);
    swap(arraySize, tmp.arraySize);
    swap(cardsLeft, tmp.cardsLeft);
    swap(cards, tmp.cards);
    return *this;
}

Deck::~Deck() {
    cout << "Destructor called" << endl;
    delete[] cards;
    cards = NULL;
}

// populate 52 cards using two given array
void Deck::populateCards() {
    int index = 0;
    for (int i = 0; i < 13; i++) {
        for (int j = 0; j < 4; j++) {
            cards[index] = Card(ranks[i], suits[j]);
            index++;
            cardsLeft++;
        }
    }
}

// swap two cards using random number generator
void Deck::shuffle() {
    srand(time(0));
    int timesToShuffle = pow(cardsLeft, 2);
    for (int i = 0; i < timesToShuffle; i++) {
        swap(cards[rand() % cardsLeft], cards[rand() % cardsLeft]);
    }
}

// remove a card
Card Deck::removeCard(int index) {
    // shift the rest of the spot forward
    Card tmp = cards[index];
    for (int i = index; i <= cardsLeft - index - 1; i++) {
        cards[i] = cards[i + 1];
    }
    // clear the last spot utilizing default constructor
    cardsLeft--;
    // return the card object
    return tmp;
}

// print the deck
void Deck::printDeck() {
    for (int i = 0; i < cardsLeft; i++) {
        cout << cards[i].printCard();
    }
}

// add a card to the array
bool Deck::addCard(Card &addCard) {
    if (cardsLeft == arraySize) {
        return false;
    } else {
        cards[cardsLeft] = addCard;
        cardsLeft++;
        return true;
    }
}

// get number of cards left in the array (current array size)
int Deck::getCardsLeft() {
    return cardsLeft;
}
