#include "Decks.h"
//Inlcuide algorithm to call built in shuffle function in c++
#include <algorithm>

//Constructs Decks. BlackJack rules of 5 deck play.
Decks::Decks() {
    for (int i = 0; i < 5; i++) {
        for (int value = 1; value <= 13; value++) {
            for (int suit = 0; suit <= 3; suit++) {
                Card deckCard = Card(value, suit);
                _cards.push_back(deckCard);
            }
        }
    }
}
//Function to shuffle deck. Built in C++ shuffle function
void Decks::shuffle() {
    std::random_shuffle(_cards.begin(), _cards.end());
}
//Pop the 1st card from deck.
Card Decks::pop() {
    Card poppedCard = _cards.front();
    _cards.erase(_cards.begin());
    return poppedCard;
}
//keep track of number of cards to figure out when to reshuffle.
int Decks::numCards() {
    return _cards.size();
}
