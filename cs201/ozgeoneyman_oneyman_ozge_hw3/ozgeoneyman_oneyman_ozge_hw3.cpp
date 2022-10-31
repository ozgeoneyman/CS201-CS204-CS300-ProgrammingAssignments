//OZGE ONEYMAN

#include "Robots_Modified.h"
#include "randgen.h"
#include "MiniFW_Modified.h"
#include "strutils.h"

using namespace std;

void CreatingRandomEnvironment()
{
	RandGen rn;
	int x,y,thing;
	int cellNum = rn.RandInt(40,169); //at least 40 cell must be populated
	for (int i = 0; i < cellNum; i++)
	{
		x= rn.RandInt(0,12); //random x coordinate
		y= rn.RandInt(0,12); //random y coordinate


		if (!((x==0) && (y==0) || (x==0) && (y==12) ||(x==12) && (y==0) || (x==12) && (y==12)
			||(x==6) && (y==6) || (x==6) && (y==2) ||(x==2) && (y==6) || (x==10) && (y==6) 
			||(x==6) && (y==10))) //these cells cannot be populated
		{
			int count= GetCellCount(x, y); 
			if (count == 0)
			{
				thing= rn.RandInt(1,4); //random number of things
				PutThings(x,y,thing);
			}
			else
			{
				i--;
			}
		}
		else
		{
			i--;
		}
	}
}


int main()
{
	CreatingRandomEnvironment();
	Robot player(6,6);
	Robot monster1(6,2);
	monster1.SetColor(red);
	Robot monster2(2,6);
	monster2.SetColor(red);
	Robot monster3(10,6);
	monster3.SetColor(red);
	Robot monster4(6,10);
	monster4.SetColor(red);

	RandGen rn;
	bool check= true;
	for (int i = 0; i < 3 && check; i++)
	{
		if (i==1)
		{
			ShowMessage("You have 2 lives left!");
		}
		else if (i==2)
		{
			ShowMessage("You have only 1 live left!");
		}

		while (player.IsAlive() && check)
		{
			if (IsPressed(keyRightArrow))
			{
				player.Turn(east);
				player.Move();
			}
			else if (IsPressed(keyLeftArrow))
			{
				player.Turn(west);
				player.Move();
			}
			else if (IsPressed(keyUpArrow))
			{
				player.Turn(north);
				player.Move();
			}
			else if (IsPressed(keyDownArrow))
			{
				player.Turn(south);
				player.Move();
			}
			player.PickAllThings();
			player.PutManyThings();

			int mons=rn.RandInt(1,4); //a random robot move when player robot start to move
			if (mons==1)
			{
				monster1.MonsterMove();

			}
			else if (mons==2)
			{
				monster2.MonsterMove();
			}
			else if (mons==3)
			{
				monster3.MonsterMove();
			}
			else 
			{
				monster4.MonsterMove();
			}
			monster1.Resurrect();
			monster2.Resurrect();
			monster3.Resurrect();
			monster4.Resurrect();
			if ((GetCellCount(0,12)==10) && (GetCellCount(0,0)==10) && (GetCellCount(12,0)==10) && (GetCellCount(12,12)==10))
			{
				ShowMessage("Congratulations, you win!");
				check= false;
			}
		}
		player.Resurrect();
	
		
	}
	if (check==true)
	{
		ShowMessage("You have no lives left!");
		ShowMessage("You just lost the game!");
	}
}

