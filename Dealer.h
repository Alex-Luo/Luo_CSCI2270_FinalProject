#ifndef DEALER_H
#define DEALER_H

#include "Hand.h"
#include "Decks.h"

class Dealer {
  private:
	void houseRules();
	Hand * _hand;
	Decks _decks;
  public:
    Dealer(Hand *hand);
    virtual ~Dealer();
    Hand getHand();
	void hit(Hand *hand);
	void stay();
	void doubleDown(Hand *hand);
};
#endif
