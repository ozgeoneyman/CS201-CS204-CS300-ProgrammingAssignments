/*Begin: code taken from LAB8-TicTacToe example player.h and updated */
#ifndef PLAYER_H
#define PLAYER_H
#include "BOARD_ozgeoneyman_oneyman_ozge_hw6.h"
#include<string>
#include<iostream>
using namespace std;


class Player
{
	public:
		Player(Board &theBoard,char id, int direc);
		
	
		void move(int num);
		int getRow()const;
		int getCol()const;
		void claimOwnership();
		
		bool wins();

	private:

		Board* board;
		int direction;
		int row;
		int col;
		char playerChar;
};

#endif
/*END: code taken from LAB8-TicTacToe example player.h and updated */
