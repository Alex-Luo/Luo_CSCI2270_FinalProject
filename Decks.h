#ifndef DECKS_H
#define DECKS_H

#include <vector>
#include "Card.h"

class Decks {
    private:
        std::vector<Card> _cards;
    public:
        Decks();
        void shuffle();
        Card pop();
        int numCards();
};

#endif
