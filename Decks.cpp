#include "Decks.h"

#include <algorithm>

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

void Decks::shuffle() {
    std::random_shuffle(_cards.begin(), _cards.end());
}

Card Decks::pop() {
    Card poppedCard = _cards.front();
    _cards.erase(_cards.begin());
    return poppedCard;
}

int Decks::numCards() {
    return _cards.size();
}
