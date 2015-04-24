#include "Hand.h"
//returns the cards
std::vector<Card> Hand::getCards() {
    return _cards;
}
//add card to hand
void Hand::addCard(Card card) {
    _cards.push_back(card);
}
//figure out value of cards
int Hand::getValue(bool dealer) {
    int returnValue = 0;
    int numAces = 0;
    for (int i = 0; i < _cards.size(); i++) {
        int cardValue = _cards[i].getValue();
        if (cardValue > 10) cardValue = 10;
        if (cardValue == 1) {
            numAces++;
            cardValue = 11;  //ace rules, if over 21, ace becomes 1 instead of 11.
        }
        returnValue += cardValue;
    }
    for (int i = 0; i < numAces; i++) {         //if the value is over 21 wth aces, change them to 1
        if (returnValue > 21) returnValue -= 10;
    }
    if (dealer && _cards.size() == 2) returnValue -= _cards[0].getValue();
    return returnValue;
}
