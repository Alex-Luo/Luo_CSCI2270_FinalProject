#include "Card.h"

Card::Card(int value, int suit) {
    _value = value;
    _suit = suit;
}

int Card::getValue() {
    return _value;
}

std::string Card::toString() {
    std::string returnString = "";
    if (_value == 1) returnString += "ace";
    else if (_value == 11) returnString += "jack";
    else if (_value == 12) returnString += "queen";
    else if (_value == 13) returnString += "king";
    else returnString += std::to_string(_value);
    returnString += " of ";
    if (_suit == 0) returnString += "clubs";
    else if (_suit == 1) returnString += "diamonds";
    else if (_suit == 2) returnString += "hearts";
    else if (_suit == 3) returnString += "spades";
    return returnString;
}
