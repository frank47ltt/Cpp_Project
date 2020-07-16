/*************************
 * author: Frank Liu (Tongtong)
 * class: CSC112
 * date: Mar 26
 * project: project 5
 *************************/


#include <iostream>
#include <string>
#include <cctype>
#include "Card.h"
#include "Deck.h"

using namespace std;

int main() {

    cout << "Welcome to Blind Man's Bluff" << endl << endl;
    // declare necessary variables
    bool play;
    bool invalid;           // keep track of the while loop
    bool guessedHigher;
    string response;
    Card compValue;
    Card userValue;         // two object of cards
    int nWin = 0;
    int nLoss = 0;
    int nTie = 0;
    int numPlayed = 0;      // keep track of time played

    // declare two decks
    Deck *origDeck = new Deck;
    Deck *discardDeck = new Deck;
    // populate and shuffle the original deck
    origDeck->populateCards();
    origDeck->shuffle();

    play = true;
    while (play && numPlayed != 26) {
        // assign values to computer and user
        // shuffle the deck and dealt the card from the top
        origDeck->shuffle();
        cout << "Shuffle the deck and distributing cards ........" << endl;
        // remove the already dealt card
        compValue = origDeck->removeCard(0);
        userValue = origDeck->removeCard(0);
        cout << "Cards left in original deck is " << origDeck->getCardsLeft() << endl;
        // add the card to the discard pile
        discardDeck->addCard(compValue);
        discardDeck->addCard(userValue);
        cout << "Cards left is discarded deck is " << discardDeck->getCardsLeft() << endl;

        // get user's bet
        cout << "Computer's value is " << compValue.printCard() << endl;
        invalid = true;
        while (invalid) {
            cout << "Do you think your number is higher or lower? (H/L)" << endl;
            cin >> response;
            if (toupper(response.at(0)) == 'H') {
                // continue playing
                guessedHigher = true;
                invalid = false;
            } else if (toupper(response.at(0)) == 'L') {
                // break out of while(play) loop
                guessedHigher = false;
                invalid = false;
            } else {
                // invalid response, ask again
                cout << "Invalid response..." << endl;
                invalid = true;
            }
        }

        // determine outcome using overloaded operator to compare objects (cards)
        if ((compValue < userValue && guessedHigher) || (compValue > userValue && !guessedHigher)) {
            cout << "Great! You're right:" << endl;
            nWin++;
        } else if ((compValue > userValue && guessedHigher) || (compValue < userValue && !guessedHigher)) {
            cout << "Sorry, you're wrong:" << endl;
            nLoss++;
        } else {
            cout << "It's a tie:" << endl;
            nTie++;
        }
        cout << "\tyour value is " << userValue.printCard() << endl;

        // ask user to play again
        invalid = true;
        while(invalid) {
            cout << "Play again? (Y/N)" << endl;
            cin >> response;
            if (toupper(response.at(0)) == 'Y') {
                // continue playing
                play = true;
                invalid = false;
            } else if (toupper(response.at(0)) == 'N') {
                // break out of while(play) loop
                play = false;
                invalid = false;
            } else {
                // invalid response, ask again
                cout << "Invalid response..." << endl;
                invalid = true;
            }
        }
        numPlayed++;
        cout << "You played " << numPlayed << " times" << endl;
    }

    // delete the deck in the heap
    // calling default constructor to delete cards
    delete origDeck;
    delete discardDeck;
    origDeck = NULL;
    discardDeck = NULL;
    // output stats
    cout << "Thanks for playing!" << endl;
    cout << "Your record was " << nWin << "-" << nLoss << "-" << nTie << " (W-L-T)" << endl;
    cout << endl;
    string user;
    cout << "Press y to start unit testing!" << endl;
    cin >> user;
    if (user == "y") {
        // Unit Testing for Card class -- printCard
        cout << "Start Unit Testing for print card! " << endl;
        Card a("Ace", "Spades");
        cout << "Expected Ace of Spades, showed " << a.printCard();
        cout << "Test End!" << endl << endl;

        // Unit Testing for Card class -- operator
        cout << "Start Unit Testing for overloaded comparison operator!" << endl;
        Card b("Queen", "Heart");
        Card c("King", "Spades");
        Card d("King", "Clubs");
        if ((b > c) && (c > d) && (b > d)) {
            cout << "operator works!" << endl;
        } else {
            cout << "operator fails" << endl;
        }
        cout << "Test End!" << endl << endl;

        // Unit Test for Big Three
        cout << "Start Unit Testing for Big Three" << endl;
        Deck *e = new Deck;
        Deck *f = new Deck(*e);
        Deck *g = new Deck;
        *g = *f;
        cout << "Test End!" << endl << endl;

        // Unit Test for other Deck member function
        cout << "Start Unit Testing for shuffle and populate" << endl;
        cout << "The print out of the card is already shuffled" << endl;
        Deck *h = new Deck;
        h->populateCards();
        h->shuffle();
        cout << "Press y to print the deck" << endl;
        cin >> user;
        if (user == "y") {
            h->printDeck();
        }
        cout << endl << "Now I will remove the first card" << endl;
        h->removeCard(0);
        cout << "Press y to print the deck" << endl;
        cin >> user;
        if (user == "y") {
            h->printDeck();
        }

        cout << endl << "Now I will add Ace of Hearts to the end of the pile" << endl;
        Card k("Ace", "Hearts");
        h->addCard(k);
        cout << "Press y to print the deck" << endl;
        cin >> user;
        if (user == "y") {
            h->printDeck();
        }
        cout << "Test end!!" << endl;
    }


    return 0;
}