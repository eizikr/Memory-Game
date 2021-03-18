/*Assignment:3
	Author: Itzik Rahamim, ID:312202351	*/
#include "Game.h"

int main() {
	srand(time(NULL));
	int cards;
	cout << "Wellcome to my memory game!\nHow many cards you want to play with? {minimum-4 , maximum-52 ,}: ";//default is 20
	cin >> cards;
	Game m(cards);
	m.Run();
	return 0;
}
