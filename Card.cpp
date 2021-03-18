/*Assignment:3
	Author: Itzik Rahamim, ID:312202351	*/
#include "Card.h"

Card::Card():status(open) {}//c'tor

void Card::changeCardStatus() {	//open or close the card
	status = !status;
}

const bool Card::compareCards(const Card& obj)const { //check if card1 sign == card2 sign
	if (sign == obj.sign)
		return true;
	return false;
}

void Card::print()const {//check if card is open and print
	if (status)
		cout << "[ " << sign << " ] ";
	else
		cout << "[ ? ] ";
}
