#include "Hand.h"
/*
Function prototype:
std::vector<Card> Hand::getCards();

Function description:
function returns the cards in players hand. 

Example:
cout << playerHand.getCards()[i].toString()<< endl;

Pre-conditions: player hand must exist. 
Post-conditions: returns the players hand
*/
std::vector<Card> Hand::getCards() {
    return _cards;
}



/*
Function prototype:
void Hand::addCard(Card);

Function description:
Adds a card to the hand

Example:
hand->addCard(_decks.pop());

Pre-conditions: card must exist and hand must exist. 
Post-conditions: hand now has an additional card that is now pushed back. 
*/
void Hand::addCard(Card card) {
    _cards.push_back(card);
}



/*
Function prototype:
int Hand::getValue(bool);

Function description:
Calculates the value of the hand

Example:
cout << "Value" << playerHand.getValue(dealer) << endl;

Pre-conditions: must have a valid hand with valid numbers and suits. 
Post-conditions: returns the value of the hand. 
*/
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
