#include "Decks.h"

#include <algorithm>
#include <random>
//build the deck
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
//shuffle function, calls upon built in algorithm and random functions
void Decks::shuffle() {
    std::mt19937 r{std::random_device{}()};
    std::shuffle(_cards.begin(), _cards.end(), r);
}
//take out a card
Card Decks::pop() {
    Card poppedCard = _cards.front();
    _cards.erase(_cards.begin());
    return poppedCard;
}
//keep track of number of cards in deck to figure out when to reshuffle
int Decks::numCards() {
    return _cards.size();
}
