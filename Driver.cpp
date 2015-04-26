#include <iostream>
#include "Dealer.cpp"

using namespace std;
void Menu(){
	cout << "Welcome to Blackjack!" << endl;
	cout <<"===================" << endl;
	cout <<"Current Balance: $" << wallet << endl;
	cout << "1. Place bet?" << endl;
	cout << "2. Quit" << endl;
}
void BetMenu(){
	cout <<"1. Hit" << endl;
	cout << "2. Double Down" << endl;
	cout <<"3. Stay" << endl;
}
void HitMenu(){
	cout <<"1. Hit" << endl;
	cout << "2. Stay" << endl;
}

int main(){
	
	string command = "0"
	int bet;
	int balance = 500;
	string bet_command = "0"
	string hit_command = "0"
	int value = playerHand.getValue(dealer);
	int dealer_value = dealer.getValue(dealer);
	while(command != "2"){
	// Loop through. As long as it's not 2(quit), it will keep printing menu after each play and ask for a bet.
		Menu();
		cin >> command;
		cin >> bet;
		//loop to make sure you don't overbet
		while(bet > balance){
			cout << "Cannot overbet" << endl;
			cout << "Bet: $";
			cin >> bet;
			cout << bet << endl;
		}
		//initial deal
		Hand playerHand;
		Dealer dealer(&playerHand);
		printPlayerHand(true, dealer.getHand());
		printPlayerhand(false, playerHand);
		
		//loop through playing stage, while not stay, hit or double down
		while(bet_command != "3"){
			//while it is hit, loop to see if they still want to keep hitting or staying, only 2 options as long as its not over 21.
			while((bet_command == "1") && (value < 21){
				dealer.hit(&playerHand);
				//loop through hitting stage, (probably messed this part up)
				while(hit_command != "2"){
					HitMenu();
					dealer.hit(&playerHand);
				}
				
			}
			// if it's double down, hit once, double bet.
			if(bet_command == "2"){
				dealer.doubleDown($playerHand);
				bet = bet + bet;
			}
			// if bust, print bust, the amount lost, and update the new balance.
			if(value > 21){
				cout << "BUST!!" << endl;
				cout << "Lose $" << bet << endl;
				balance = balance - bet;
			}
			// if dealer busts, update balance and win money.
			if((value < 21) && (dealer_value > 21)){
				cout << "Dealer Busts!" << endl;
				cout << "Win $" << bet << "!" << endl;
				balance = balance + bet;
				
			}
			// if no one busts but your value is higher, you win.
			if((value < 21) && (dealer_value > 21) && (value > dealer_value)){
				cout << "Win!" << endl;
				cout << "Win $" << bet << "!" << endl;
				balance = balance + bet;
				
			}
			// if no one busts but your value is lower, you lose.
			if((value < 21) && (dealer_value > 21) && (value < dealer_value)){
			cout << "Lost!" << endl;
			cout << "Lose $" << bet << "!" << endl;
			balance = balance - bet;
			}
			// if values are tied, balance stays the same. Push
			if(value == dealer_value){
				cout << "Push!" << endl;
			}
		} 
	}
	
}
}
