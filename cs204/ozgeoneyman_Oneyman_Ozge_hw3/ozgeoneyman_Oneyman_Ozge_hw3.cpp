
//OZGE ONEYMAN 
//24906

#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>

#include "ozgeoneyman.h"


using namespace std;

void MainMenu()  
{
	cout<<"1) Upload Card(s) from a File "<<endl;
	cout<<"2) Display List Chronological "<<endl;
	cout<<"3) Display List Reverse Chronological "<<endl;
	cout<<"4) Card Search "<<endl;
	cout<<"5) Bulk Delete "<<endl;
	cout<<"6) Exit "<<endl;
	cout<<"Please choose option from the menu: "; 
}

bool checkmonth(int month)  //checking the card's month given true or not
{
	if (1<=month && month<=12)
	{
		return true;
	}
	else
	{
		return false;
	}
}
/*Begin: code taken from ozgeoneyman_Oneyman_Ozge_hw2.cpp and updated */
bool optioncheck(int choice)
{
	if (choice==1 || choice==2 ||choice==3 || choice==4 || choice==5 || choice== 6) //choice must be only these values
	{
		return true;
	}	
	else 
		return false;
}
/*End: code taken from ozgeoneyman_Oneyman_Ozge_hw2.cpp and updated*/


/*Begin: code taken from ozgeoneyman_Oneyman_Ozge_hw2.cpp and updated*/
bool cardnumcheck(string num)  //for checking the cardnum in the option 4
{
	bool check=true, check2=true;
	if (num.length()!=16)  //card num's length must be equal to 16
	{
		check=false;
	}
	else
	{
		for (int i = 0; i < num.length() && check2==true; i++)
		{

			if ('0' <= num.at(i) && num.at(i) <= '9')   // and only be postive integers
			{

				check= true;

			}
			else
			{
				check=false;
				check2=false;
			}

		}
	}
	return check;

}
/*End: code taken from ozgeoneyman_Oneyman_Ozge_hw2.cpp and updated*/

int main()
{
	int option=0, cardmon, cardyear;
	string file, line, cardnum, num;
	ifstream myfile;
	CardList list;



	/*Begin: code taken from ozgeoneyman_Oneyman_Ozge_hw2.cpp and updated */

	while (option != 6)
	{
		MainMenu();
		cin>>option;

		if( cin.fail() || optioncheck(option)==false)  //checking the option value is valid or not
		{
			cin.clear();
			cin.ignore(INT_MAX,'\n');
			cout<<"Invalid Operation! "<<endl<<endl;
			MainMenu();
			cin>>option;
		}

		if (option==1)
		{
			

			cout<< "Please enter file name: ";
			cin >> file;
			cout<<endl;
			myfile.open(file.c_str());


			if (myfile.fail())
			{

				myfile.clear();					//for reading new txt
				cout<< "Could not find a file named " << file << endl<<endl;

				cout<<endl;
				continue;

			}



			while (!(myfile.eof()))
			{
				while (getline(myfile, line))
				{
					stringstream iss(line);

					iss>> cardnum>> cardmon >> cardyear;

					list.insertCard(cardnum,cardmon,cardyear);  //making the linked list
			

				}

			}

			myfile.close();
			cout<<endl;


		}

		else if (option==2)		//display list
		{
			cout<<endl;
			list.displayListChronological();
			cout<<endl;
		}
		else if (option==3)   //display list in reverse order
		{
			cout<<endl;
			list.displayListReverseChronological();
			cout<<endl;
		}
		else if (option==4)   //card search
		{
			cout<<"Please enter the credit card number: ";
			cin>> num;
			bool check= cardnumcheck(num); //cardnum is in valid format or not
			if (check==false)
			{
				cout<<"Invalid format! "<<endl;
				cout<<endl;

				continue;
			}
			list.cardSearch(num);
			cout<<endl;
		}
		else if (option==5)   //bulk delete
		{
			int pmonth,pyear;

			cout<<"Please enter month and year: ";
			cin>> pmonth>> pyear;
			checkmonth(pmonth); //checking for valid dates or not
			cout<<endl;
			/*Begin: code taken from ozgeoneyman_Oneyman_Ozge_hw1.cpp and updated */
			if (checkmonth(pmonth)==false || cin.fail())
			{
				cin.clear();
				cin.ignore(INT_MAX,'\n');
				cout<<"Invalid format! "<<endl;
				cout<<endl;
				continue;

			}
			else
			{
				list.bulkDelete(pmonth,pyear);
				cout<<endl;

			}
			/*End: code taken from ozgeoneyman_Oneyman_Ozge_hw1.cpp and updated */
		}

	}

	if (option==6)		//deleting the linked list
	{
		list.deleteAll();
		cout<<"All the nodes have been deleted!"<<endl; 
		cout<<"Terminating..."<<endl;
	}

	/*End: code taken from ozgeoneyman_Oneyman_Ozge_hw2.cpp and updated */


}

