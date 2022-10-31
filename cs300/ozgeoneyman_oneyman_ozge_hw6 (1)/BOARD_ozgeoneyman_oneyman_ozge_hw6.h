/*Begin: code taken from LAB8-TicTacToe example board.h and updated */
#ifndef BOARD_H 
#define BOARD_H

#include<string>
using namespace std;

class Board
{
	public:
		Board();  //default constructor
		
		int countOwnedCells(char player)const;
	
		void displayBoard()const;   // displaying board
		char getOwner(int row, int col)const;
		void setOwner(int row, int col, char player);
		bool isFull()const; //board full or nor

	private:
		char theBoard[2][6];
	
};
#endif
/*End: code taken from LAB8-TicTacToe example board.h and updated */
