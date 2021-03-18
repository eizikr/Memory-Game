/*Assignment:3
	Author: Itzik Rahamim, ID:312202351	*/
#ifndef _PILE_H
#define _PILE_H
#include "Card.h"
#include <time.h>
#include <ctime>
#include <stdlib.h>
#define MIN_CARDS 4
#define MAX_CARDS 52
#define DEFAULT 20

class Pile {
	Card* packet;						//packet
	int size;							//how many cards is in the packet
public:
	Pile(int = DEFAULT);				//default = 20
	~Pile();							//d'tor
	Card& getCard(int index)const;//get card in specific index
	void printWholePacket()const;		//print the whole board
	void fillPacket();					//fill packet with chars
	void mixPacket();					//mix the packet
	void hideThePacket();					//make the whole packet hide
	void flipTheCard(int);					//open or close card
	const int getSize()const { return size; }	//get how many cards is in the packet

};
#endif // !_PILE_H