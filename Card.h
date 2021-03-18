/*Assignment:3
	Author: Itzik Rahamim, ID:312202351	*/
#ifndef _CARD_H
#define _CARD_H
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
enum status { close, open };


class Card {
	bool status;	//the card is open or close
	char sign;		//card sign
public:
	Card();			//c'tor
	void changeCardStatus();						//open or close card
	const bool compareCards(const Card& obj)const;		//check if card1 == card2
	void print()const;								//print card
	void setCardSign(char _sign) { sign = _sign; }	//seter for the sign
	bool isOpen() { return status; }
};
#endif // !_CARD_H