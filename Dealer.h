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
    virtual ~Dealer();
    Hand getHand();
    void deal(Hand *hand);
	void hit(Hand *hand);
	void stay();
	void doubleDown(Hand *hand);
};
#endif
