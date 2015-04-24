#include "Card.h"
//card constructor
Card::Card(int value, int suit) {
    _value = value;
    _suit = suit;
}
//return balues
int Card::getValue() {
    return _value;
}
//suits and face cards to respectable numbers
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
