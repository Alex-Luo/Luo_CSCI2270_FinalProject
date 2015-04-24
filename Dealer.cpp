#include "Dealer.h"

Dealer::Dealer(Hand *hand) {
    _hand = new Hand;
    hit(hand);
    hit(_hand);
    hit(hand);
    hit(_hand);
}

Dealer::~Dealer() {
    delete _hand;
}

void Dealer::hit(Hand *hand) {
	//Deal 1 card
	hand->addCard(_decks.pop());
}

void Dealer::stay() {
	//Do nothing, pass to house.
	houseRules();
}

void Dealer::doubleDown(Hand *hand) {
	//Hit once, then has to stay.
	hit(hand);
	stay();
}

Hand Dealer::getHand() {
    return *_hand;
}

 //Typical BlackJack Rules. If dealer hand is less than 17, dealer must hit.
void Dealer::houseRules() {
	while(_hand->getValue(false) < 17){
		hit(_hand);
	}
}
