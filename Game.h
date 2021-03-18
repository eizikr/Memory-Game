/*Assignment:3
	Author: Itzik Rahamim, ID:312202351	*/
#ifndef _GAME_H
#define _GAME_H
#include "Pile.h"

class Game {
	Pile packet;
	int muches;
	const bool askContinue()const;	//ask user if he want to continue
	const int getIndexFromUser()const;				//calculate index by row and col
public:
	Game(int);					//c'tor
	void Run();					//the whole game
};
#endif // !_GAME_H