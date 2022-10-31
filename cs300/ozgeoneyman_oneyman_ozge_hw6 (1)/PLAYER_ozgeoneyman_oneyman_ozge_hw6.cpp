/*BEGIN: code taken from LAB8-TicTacToe example player.cpp and updated */
#include "PLAYER_ozgeoneyman_oneyman_ozge_hw6.h"
#include "BOARD_ozgeoneyman_oneyman_ozge_hw6.h"
#include<iostream>
#include<string>

using namespace std;

Player::Player(Board &theBoard,char id, int direc ) //constructor
{
	board= &theBoard;
	row=0;
	col=0;
	direction=direc;
	playerChar=id;

}
int Player:: getCol() const
{
	return col;
}
int Player:: getRow() const
{
	return row;
}
void Player::move(int num)
{
	if (direction==1)
	{
		if (row==0)
		{
			if (col+num<=5)
			{
				col=col+num;
			}
			else if (col+num>=6)
			{
				row++;
				col=6-(num-(5-col));
			}
		}		
		else if (row==1)
		{
			if (col-num >= 0)
			{
				col=col-num;
			}
			else if (col-num <0)
			{
				row--;
				col=(num-col)-1;
			}
		}
	}
	else if (direction==0)
	{
		if (row==1)
		{
			if (col+num<=5)
			{
				col=col+num;
			}
			else if (col+num>=6)
			{
				row--;
				col=6-(num-(5-col));
			}
		}		
		else if (row==0)
		{
			if (col-num>=0)
			{
				col=col-num;
			}
			else if (col-num<0)
			{
				row++;
				col=(num-col)-1;

			}
		}
	}
	this->col=col;
	this->row=row;
	
}

void Player::claimOwnership()
{

	if (board->getOwner(row, col)=='-')
	{
		board->setOwner(row, col, playerChar);
	}

}

bool Player::wins()   //checking who is the winner
{

	if (board->countOwnedCells(playerChar)!= 7)
	{
		return false;
	}
	else if(board->countOwnedCells(playerChar)== 7)
	{
		return true;
	}

}
/*End: code taken from LAB8-TicTacToe example player.cpp and updated */