#ifndef CARD_H
#define CARD_H

#include <string>

// Suits
// clubs = 0
// diamonds = 1
// hearts = 2
// spades = 3

// Values
// ace = 1
// 2-10
// jack = 11
// queen = 12
// king = 13

class Card {
    private:
        int _value;
        int _suit;
    public:
        Card(int value, int suit);
        int getValue();
        std::string toString();
};

#endif
