#include "Card.h"
/*
Function prototype:
Card(int, int);

Function description:
Constructor to initilize a new card that has a given value and suit.

Example:
Card deckCard = Card(5, 0)

Pre-conditions: 1 <= value <= 14; 0 <= suit <= 3
Post-conditions: returns a card
*/

Card::Card(int value, int suit) {
    _value = value;
    _suit = suit;
}


/*
Function prototype:
int Card::getValue();

Function description:
This function returns a cards given value

Example:
cardValue = _cards.getValue();

Pre-conditions: card must have a pre assigned value. 
Post-conditions: returns the cards value. 
*/
int Card::getValue() {
    return _value;
}


/*
Function prototype:
std::string Card::toString();

Function description:
This function returns the name of the card back in accordance to the card value;

Example:
cout << playerHand.getCard()[i].toString() << endl;

Pre-conditions: there has to be an assigned value between 1-14 to the card. 
Post-conditions: returns the name of the card
*/
std::string Card::toString() {
    std::string returnString = "";
    if (_value == 1) returnString += "Ace";
    else if (_value == 11) returnString += "Jack";
    else if (_value == 12) returnString += "Queen";
    else if (_value == 13) returnString += "King";
    else returnString += std::to_string(_value);
    returnString += " of ";
    if (_suit == 0) returnString += "Clubs";
    else if (_suit == 1) returnString += "Diamonds";
    else if (_suit == 2) returnString += "Hearts";
    else if (_suit == 3) returnString += "Spades";
    return returnString;
}
