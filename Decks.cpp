#include "Decks.h"

#include <algorithm>
#include <random> //algorithm and random used for shuffling randomly


/*
Function prototype:
Dekcs::Decks();

Function description:
Creates the 5 deck Deck that is typically used in casinos. 

Example:
Decks.Decks();

Pre-conditions: none
Post-conditions: creates the deck used for the game.
*/
Decks::Decks() {
    for (int i = 0; i < 5; i++) {
        for (int value = 1; value <= 13; value++) {
            for (int suit = 0; suit <= 3; suit++) {
                Card deckCard = Card(value, suit);
                _cards.push_back(deckCard);
            }
        }
    }
    //shuffle the deck
    shuffle();
}


/*
Function prototype:
void Decks::shuffle();

Function description:
randomly shuffles

Example:
shuffle();

Pre-conditions: deck has to be created. 
Post-conditions: returns nothing, deck is now shuffled. 
*/
void Decks::shuffle() {
    std::mt19937 r{std::random_device{}()};
    std::shuffle(_cards.begin(), _cards.end(), r);
}


/*
Function prototype:
Card Decks::pop();

Function description:
Function takes the 1st card out of the deck and returns it as a popped card. 

Example:
hand->addCard(_decks.pop());

Pre-conditions: card must exist in the deck. 
Post-conditions: returns popped card and erases the card from deck. 
*/
Card Decks::pop() {
    Card poppedCard = _cards.front();
    _cards.erase(_cards.begin());
    return poppedCard;
}



/*
Function prototype:
int Dekcs::numCard();

Function description:
Keep track of how many cards are in the deck. 

Example:
num_cards=decks.numCards();

Pre-conditions: deck must exist. 
Post-conditions: returns the size of deck. 
*/
int Decks::numCards() {
    return _cards.size();
}
