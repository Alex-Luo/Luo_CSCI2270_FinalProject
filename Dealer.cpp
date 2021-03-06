#include "Dealer.h"

/*
Function prototype:
Dealer::Dealer()

Function description:
Constructor that sets _hand to 0.

Example:
Automaticly called

Pre-conditions: none
Post-conditions: hand is set to 0
*/
Dealer::Dealer()
	:_hand (0) {}

/*
Function prototype:
Dealer::~Dealer()

Function description:
Destructor that deletes hand.

Example:
Automaticly called

Pre-conditions: hand must exist 
Post-conditions: hand is deleted so you can play a new round.
*/
Dealer::~Dealer() {
	if (_hand)
		delete _hand;
}



/*
Function prototype:
Dealer::deal(Hand *hand);

Function description:
This function creates the dealers hand and starts the game by giving each player 2 cards. It also ensures there are enough cards in the deck.

Example:
dealer.deal(&playerHand);

Pre-conditions: Must have a hand created. Calls in a hand and hands must exist that are being hit. 
Post-conditions: Dealer has a hand. Player hand has 2 cards, dealer hand has 2 cards. 
*/
void Dealer::deal(Hand *hand) {
	if (_hand)
		delete _hand;
	_hand = new Hand;
    // reshuffle cards if there aren't many left
    if (_decks.numCards() < 50) {
        _decks = Decks();
    }
    hit(hand); //alternate hitting like in a standard blackjack game.
    hit(_hand);
    hit(hand);
    hit(_hand);
}



/*
Function prototype:
void Delaer::hit(Hand);

Function description:
Deals a card to a hand

Example:
dealer.hit(&playerHand)

Pre-conditions: hand must exist 
Post-conditions: added card to players hand.
*/
void Dealer::hit(Hand *hand) {
	//Deal 1 card
	hand->addCard(_decks.pop());
}



/*
Function prototype:
void Dealer::stay();

Function description:
Function allows player to do nothing and allows the house to follow house rules. 

Example:
dealer.stay();

Pre-conditions: none
Post-conditions: Dealer follows houseRules() function and gets cards. 
*/
void Dealer::stay() {
	//Do nothing, pass to house.
	houseRules();
}



/*
Function prototype:
void Dealer::doubleDown(Hand);

Function description:
Function allow one hit and then has to stay

Example:
dealer.doubleDown(&playerHand);

Pre-conditions: Hand must exist
Post-conditions: player gets one card, then dealer follows house rules to get cards. 
*/
void Dealer::doubleDown(Hand *hand) {
	//Hit once, then has to stay.
	hit(hand);
	stay();
}



/*
Function prototype:
Hand Dealer::getHand()

Function description:
Function gets the dealer hand.

Example:
printPlayerHand(true, dealer.getHand());

Pre-conditions: none
Post-conditions: returns dealer hand.
*/
Hand Dealer::getHand() {
    return *_hand;
}



/*
Function prototype:
void Dealer::houseRules()

Function description:
Dealer follows house rules. Hits until over 17.

Example:
houseRules() 
(As seen from above in hit and double down function)

Pre-conditions: none
Post-conditions: dealer gets new cards added.
*/
void Dealer::houseRules() {
	while(_hand->getValue(false) < 17){
		hit(_hand);
	}
}
