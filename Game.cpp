/*Assignment:3
	Author: Itzik Rahamim, ID:312202351	*/
#include "Game.h"

Game::Game(int cardsNumber) :packet(cardsNumber), muches(0) {}//c'tor

void Game::Run() {//game management 
	int index_1, index_2 ,flag = 0;
	do
	{
		packet.printWholePacket();
		//get 2 indexes from user and open the card 
		cout << "Please choos your first card (Enter row and column):" << endl;
		index_1 = getIndexFromUser();
		while (packet.getCard(index_1).isOpen()) {
			cout << "sorry this card is already open" << endl;
			index_1 = getIndexFromUser();
		}
		packet.flipTheCard(index_1);
		packet.printWholePacket();
		cout << "Now choos your second card (Enter row and column):" << endl;
		index_2 = getIndexFromUser();
		while (packet.getCard(index_2).isOpen()) {
			cout << "sorry this card is already open" << endl;
			index_2 = getIndexFromUser();
		}
		packet.flipTheCard(index_2);
		packet.printWholePacket();

				/////check if Match between both cards/////
		if (packet.getCard(index_1).compareCards(packet.getCard(index_2))) {
			muches++; //score += 1
			cout << "Its a match!\n(" << muches << " matches) " << endl;
			if (muches == packet.getSize() / 2) {
				cout << "Congratulations, you won!\nSee you on the next mission!";
				exit(1);
			}
			else if (!askContinue())//ask user if he want to continue
				flag = 1;
		}
		else {
			packet.flipTheCard(index_1);
			packet.flipTheCard(index_2);
			cout << "Sorry, no match... \n(" << muches << " matches) " << endl;
			if (!askContinue())//ask user if he want to continue
				flag = 1;
		}
		system("cls");
	} while (!flag); //if game isn't finished
	cout << "Thank you for playing!\nSee you on the next mission!";
}

const bool Game::askContinue()const{//ask the user if he want to continue playing
	bool answer;
	cout << "Would you like to continue? {1 - yes, 0 - no} : ";
		cin >> answer;
		return answer;
}

const int Game::getIndexFromUser()const {//calculate the index by the rows and columns that user choosed 
	int row, col, num;
	cout << "row:";
	cin >> row;
	cout << "col:";
	cin >> col;
	num = 5 * row - 6 + col;
	if (row <= 0 || col <= 0 || col > 5 || num >= packet.getSize() || num < 0) {//check if the index is legal
		cout << "there is no card with this index, Goodbye!";
		exit(1);
	}
	return num;
}