/*Begin: code taken from LAB8-TicTacToe example board.cpp and updated */
#include "BOARD_ozgeoneyman_oneyman_ozge_hw6.h"
#include <iostream>

using namespace std;


Board::Board()  //making board
{
	for(int i=0; i<2; i++)
	{
		for(int j=0; j<6; j++)
		{
			theBoard[i][j] ='-';
		}
	}
}



void Board::displayBoard()const    //printing board
{
	cout << "Board: " << endl;
	for(int i=0; i<2; i++)
	{
		for(int j=0; j<6; j++)
		{
			cout << theBoard[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}

char Board::getOwner(int row, int col)const    //who is own that cell?
{
	if (theBoard[row][col]=='A')
	{
		return 'A';
	}
	else if (theBoard[row][col]=='B')
	{
		return 'B';
	}
	else
	{
		return '-';
	} 

}

void Board::setOwner(int row, int col, char player)   //setting the owner
{
	theBoard[row][col]= player;
}

int Board::countOwnedCells(char player)const   //count player's cell number
{
	int count = 0;
	for(int i=0; i<2; i++)
	{
		for(int j=0; j<6; j++)
		{
			if(theBoard[i][j] == player )
			{
				count++;
			}
		}
	}
	return count;
}

bool Board::isFull()const    //checking the board is full or not
{
	int countFullCells = 0;
	for(int i=0; i<2; i++)
	{
		for(int j=0; j<6; j++)
		{
			if(theBoard[i][j] == '-' )
			{
				return false;
			}
		}
	}
	return true;
}
/*Begin: code taken from LAB8-TicTacToe example board.cpp and updated */
