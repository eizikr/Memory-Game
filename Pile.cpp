/*Assignment:3
	Author: Itzik Rahamim, ID:312202351	*/
#include "Pile.h"

Pile::Pile(int num):size(num){//c'tor
	if (size > MAX_CARDS || size < MIN_CARDS)		////////////////////////////////
		size = DEFAULT;								//check if 52 > size > 4	  //
	if (size % 2 == 1)								//if not size = 20			  //
		size--;										//if size isn't even size -= 1//
	packet = new Card[size];						//allocate memory for packet  //
	fillPacket();									//fill the packet with chars  //
	mixPacket();									//mix the packet			  //
}													////////////////////////////////

Pile::~Pile() {//d'tor
	delete[] packet;//delete allocated packet
}

Card& Pile::getCard(int spot)const {
	if (spot < 0 || spot >= size) {	
		//if index isn't exist get out
		cout << "there is no card with index"<< spot << "Goodbye!";
		exit(1);
	}
	return packet[spot];	//return the specific card
}

void Pile::printWholePacket()const {//print the whole packet
	int row = 1;
	cout << "\t  1\t  2\t  3\t  4\t  5";//show columns
	for (int i = 0; i < size; i++){
		if (i % 5 == 0)//every 5 columns get down
			cout << "\n" << row++;//print the row and row += 1
		cout << "\t";
		packet[i].print();//print the card
	}
	cout << "\n" << endl;
}

void Pile::fillPacket() {//fill packet with chars
	char sign = 'A';//first char
	for (int i = 0; i < size; i+=2) {
		//fill every 2 cards with the same char
		packet[i].setCardSign(sign);
		packet[i+1].setCardSign(sign);
		sign++;//next char by acci table
	}
}

void Pile::mixPacket() {//mix the packet
	int spot;
	Card help_Card;
	for (int i = 0; i < size; i++) {//random sort "size" times
		spot = rand() % (size-1) + 0;
		help_Card = packet[i];
		packet[i] = packet[spot];
		packet[spot] = help_Card;
	}
	system("cls");	//clean screen to start the game
	cout << "Get ready, you got only 30 seconds to remember:" << endl;
	printWholePacket();
	//count 30 seconds before hide the cards//
	int sec = 30;
	clock_t start_time = clock();
	clock_t end_time = sec * 1000 + start_time;
	while (clock() != end_time);
	//after 30 seconds clean end hide cards//
	system("cls");
	hideThePacket();
}

void Pile::hideThePacket() {//close whole cards
	for (int i = 0; i < size; i++)
		packet[i].changeCardStatus();
}

void Pile::flipTheCard(int spot) {//open or close specific card
		packet[spot].changeCardStatus();
}