#ifndef HAND_H
#define HAND_H

#include <vector>
#include "Card.h"

class Hand {
    private:
        std::vector<Card> _cards;
    public:
        std::vector<Card> getCards();
        void addCard(Card card);
        int getValue(bool dealer);
};

#endif
