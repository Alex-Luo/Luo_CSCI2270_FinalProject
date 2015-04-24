#include "Hand.h"

std::vector<Card> Hand::getCards() {
    return _cards;
}

void Hand::addCard(Card card) {
    _cards.push_back(card);
}

int Hand::getValue(bool dealer) {
    int returnValue = 0;
    int numAces = 0;
    for (int i = 0; i < _cards.size(); i++) {
        int cardValue = _cards[i].getValue();
        if (cardValue > 10) cardValue = 10;
        if (cardValue == 1) {
            numAces++;
            cardValue = 11;
        }
        returnValue += cardValue;
    }
    for (int i = 0; i < numAces; i++) {
        if (returnValue > 21) returnValue -= 10;
    }
    if (dealer && _cards.size() == 2) returnValue -= _cards[0].getValue();
    return returnValue;
}
