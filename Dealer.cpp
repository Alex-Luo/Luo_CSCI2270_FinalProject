#include "Dealer.h"

void Dealer::Hit(Hand *hand){
	//Deal 1 card
	hand->addCard(_decks.pop());
}

void Dealer::Stay(){
	//Do nothing, pass to house.
	HouseRules();
}

void Dealer::DoubleDown(Hand *hand){
	//Hit once, then has to stay.
	Hit(hand);
	Stay();
}
 //Typical BlackJack Rules. If dealer hand is less than 17, dealer must hit.
void Dealer::HouseRules(){
	while(_hand->getValue() < 17){
		Hit(_hand);
	}
}
