#indef DEALER_H
#define DEALER_H
#include "Hand.h"
#include "Decks.h"
class Dealer:{
  private:
	void HouseRules();
	Hand * _hand;
	Decks _decks;
	
  public:
	void Hit();
	void Stay();
	void DoubleDown();
	
};
#endif
