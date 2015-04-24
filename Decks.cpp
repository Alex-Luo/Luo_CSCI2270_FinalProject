#include "Decks.h"

#include <algorithm>
#include <random>

Decks::Decks() {
    for (int i = 0; i < 5; i++) {
        for (int value = 1; value <= 13; value++) {
            for (int suit = 0; suit <= 3; suit++) {
                Card deckCard = Card(value, suit);
                _cards.push_back(deckCard);
            }
        }
    }
    shuffle();
}

void Decks::shuffle() {
    std::mt19937 r{std::random_device{}()};
    std::shuffle(_cards.begin(), _cards.end(), r);
}

Card Decks::pop() {
    Card poppedCard = _cards.front();
    _cards.erase(_cards.begin());
    return poppedCard;
}

int Decks::numCards() {
    return _cards.size();
}
