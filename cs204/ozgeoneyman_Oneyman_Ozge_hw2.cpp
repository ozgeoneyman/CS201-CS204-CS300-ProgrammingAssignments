
//OZGEONEYMAN 24906
//CS204 homework 2

#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>


using namespace std;

struct node //for keeping values of month, year,cards and next node
{
	int month, year;
	vector<string> cards;
	node* next;

};

/*Begin: code taken from linkedList.cpp */
void clearlist(node*head) //clearing list for option four
{
	node *ptr;
	while (head!=NULL)
	{
		ptr=head;
		head=head->next;
		delete ptr;
	}
}
/*End: code taken from linkedList.cpp */

bool checkchoice(int choice)
{
	if (choice==1 || choice==2 ||choice==3 || choice==4) //choice must be only these values
	{
		return true;
	}	
	else 
		return false;
}

/*Begin: code taken from linkedList.cpp and updated */
bool searching (node* head, int cardmon, int cardyear, string cardnum)	
{
	// this function use when a node with same date created before and add the credit card num 
	while (head != NULL)
	{
		if (head->year== cardyear && head->month== cardmon)
		{
			head->cards.push_back(cardnum);
			return true;

		}
		head= head->next;
	}
	return false;
}
/*End: code taken from linkedList.cpp and updated */

void sortandsearch(node*&head, int cardmon, int cardyear, string cardnum) //creating linked list
{
	node*temp=head;
	node *ptr;
	ptr= new node;
	if (head->year > cardyear || (head->year == cardyear && head->month > cardmon)) //if node will be add to beginning
	{
		ptr->next= head;
		ptr->month= cardmon;
		ptr->year= cardyear;
		ptr->cards.push_back(cardnum);
		head=ptr;
		return;
	}
	while (temp != NULL)
	{
		//if node will be add end of the linked list
		if ((temp->next== NULL && temp->year < cardyear)||  (temp->year == cardyear && temp->next== NULL && temp->month < cardmon ))
		{
			temp->next= ptr;
			ptr->month= cardmon;
			ptr->year= cardyear;
			ptr->cards.push_back(cardnum);
			ptr->next= NULL;
			break;
		}
		else if ((temp->year < cardyear && cardyear < temp->next->year )||(temp->year == cardyear && temp->next->year==cardyear &&temp->month < cardmon && cardmon < temp->next->month ))
		{
			//if node add in the middle 
			ptr->next= temp->next;
			temp->next= ptr;
			ptr->month= cardmon;
			ptr->year= cardyear;
			ptr->cards.push_back(cardnum);
			break;
		}

		else if ((temp->year== cardyear && temp->month < cardmon) || (temp->next->year==cardyear && temp->next->month >cardmon))
		{
			//if node add in the middle 
			ptr->next=temp->next;
			temp->next=ptr;
			ptr->month=cardmon;
			ptr->year=cardyear;
			ptr->cards.push_back(cardnum);
			break;

		}
		temp=temp->next;
	}

}

void printinglist(node* head) //for option one printing linked list
{
	while (head != NULL)
	{
		cout<< "Expiration Date: " <<head->month << "  "<< head->year<<endl;
		/*Begin: code taken from linkedList.cpp and updated */
		for (int i = 0; i < head->cards.size(); i++)
		{
			cout<< i+1<<") "<<head->cards[i]<<endl;
		}
		cout<<"-------------------"<<endl<<endl;
		head=head->next;
		/*End: code taken from linkedList.cpp and updated */
	}
}

bool cardnumcheck(string num)  //for checking the cardnum in the option 2
{
	bool check=true;
	if (num.length()!=16)  //card num's length must be equal to 16
	{
		check=false;
	}
	else
	{
		for (int i = 0; i < num.length(); i++)
		{

			if ('0' <= num.at(i) && num.at(i) <= '9')   // and only be postive integers
			{

				check= true;

			}
			else
			{
				check=false;
				break;
			}

		}
	}
	return check;

}

void cardsearch(node* head, string num) //checking the cardnum is valid or not for option 2
{
	int count=0;
	while (head!=NULL)
	{
		for (int i = 0; i < head->cards.size(); i++)
		{
			if (head->cards[i]==num)
			{
				cout<<"There exists a credit card number: "<<num<< " with expiration date: "<< head->month<<" "<<head->year<< endl;
				count++;
				break;
			}
		}
		if (count!=0)
		{
			break;
		}
		head=head->next;
	}
	if (count==0)
	{
		cout<<"There is no credit card with given credit card number: "<< num <<endl;

	}

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

/*Begin: code taken from linkedList.cpp and updated */
bool searchmonthyear(node* head, int imonth,int iyear) //search for option 3 and checking for that date's node is available or not
{
	while (head!=NULL)
	{
		if (head->month== imonth && head->year== iyear )
		{
			return true;
		}
		head=head->next;
	}
	return false;
}
/*End: code taken from linkedList.cpp and updated */

void deletingnode(node* &head, int pmonth, int pyear) //deleting the node for option four
{
	node * s=head,*a;
	bool check=false;
	if(s->next== NULL && (s->month== pmonth && s->year== pyear) ) //if only one node occur and user wants to delete that node
	{
		cout<<"Node with expiration date "<<pmonth<<" "<<pyear<<" and the following credit cards have been deleted! " <<endl;
		for (int i = 0; i < s->cards.size(); i++)
		{
			cout<< i+1<<") "<<s->cards[i]<<endl;
		}
		a=s;
		s=s->next;

		delete a;
		check=true;
		head=s;


	}
	while (s!=NULL && check==false)
	{


		if ((s->next->month==pmonth && s->next->year==pyear ) && s->next->next==NULL) //if user wants to delete last node
		{
			cout<<"Node with expiration date "<<pmonth<<" "<<pyear<<" and the following credit cards have been deleted! " <<endl;
			for (int i = 0; i < s->next->cards.size(); i++)
			{
				cout<< i+1<<") "<<s->next->cards[i]<<endl;
			}
			a=s->next;
			s->next=NULL;
			delete a;
			break;
		}
		else if (s->next->month==pmonth && s->next->year==pyear) //if user wants to delete a node in the middle
		{
			cout<<"Node with expiration date "<<pmonth<<" "<<pyear<<" and the following credit cards have been deleted! " <<endl;
			for (int i = 0; i < s->next->cards.size(); i++)
			{
				cout<< i+1<<") "<<s->next->cards[i]<<endl;
			}
			a=s->next;
			s->next=s->next->next;
			delete a;
			break;

		}
		else if (  s->next!= NULL && (s->month== pmonth && s->year== pyear)) //if user wants to delete first node in the list
		{
			cout<<"Node with expiration date "<<pmonth<<" "<<pyear<<" and the following credit cards have been deleted! " <<endl;
			for (int i = 0; i < s->cards.size(); i++)
			{
				cout<< i+1<<") "<<s->cards[i]<<endl;
			}
			a=s;
			s=s->next;
			head=s;
			delete a;
			break;
		}



		s=s->next;
	}

} 

int main()
{
	string line, file, cardnum; 
	int cardmon, cardyear, count=0;
	ifstream myfile;
	bool check;
	cout<< "Please enter file name: ";
	cin >> file;
	myfile.open(file);  

	while (myfile.fail())
	{
		cout<< "Cannot find a file named " << file << endl;
		cout<< "Please enter file name: ";
		cin>> file;
		myfile.open(file);
	}

	node *head;  
	head=NULL;

	while (!(myfile.eof()))
	{
		while (getline(myfile, line))
		{
			stringstream iss(line);

			iss>> cardnum>> cardmon >> cardyear;

			if(head==NULL)   //creating first node 
			{
				head= new node;
				head->cards.push_back(cardnum);
				head->month = cardmon;
				head->year = cardyear;
				head->next = NULL;

				cout<< "New node is created with expiration date: "<<cardmon <<" "<<cardyear<<endl;
				cout<< "Credit card "<<cardnum<<" added to node "<< cardmon <<" "<<cardyear<<endl;
				cout<<"***************"<< endl;


			}
			else
			{

				check = searching(head,cardmon,cardyear,cardnum); //checking if that date node created or not
				if (check)
				{
					cout<< "Node with expiration date "<<cardmon <<" "<<cardyear<<" already exists"<<endl;
					cout<< "Credit card "<<cardnum<<" added to node "<< cardmon <<" "<<cardyear<<endl;
					cout<<"***************"<< endl;
				}
				else
				{
					sortandsearch(head,cardmon, cardyear, cardnum); //creating a new node
					cout<< "New node is created with expiration date: "<<cardmon <<" "<<cardyear<<endl;
					cout<< "Credit card "<<cardnum<<" added to node "<< cardmon <<" "<<cardyear<<endl;
					cout<<"***************"<< endl;

				}

			}


		}


	}


	int choice;
	string num;
	cout<<endl;
	cout<<"1) Display List "<<endl;
	cout<<"2) Card Search via Credit Number " <<endl;
	cout<<"3) Delete Card with respect to Expiration Date "<<endl;
	cout<<"4) Exit "<<endl<<endl ;

	cout<<"Please choose option from the menu: ";
	cin>> choice;


	while (choice!=4)
	{
		/*Begin: code taken from ozgeoneyman_Oneyman_Ozge_hw1.cpp and updated */
		if( cin.fail() || checkchoice(choice)==false)  //checking the option value is valid or not
		{
			cin.clear();
			cin.ignore(INT_MAX,'\n');
			cout<<"Invalid option! "<<endl<<endl;
			cout<<"1) Display List "<<endl;
			cout<<"2) Card Search via Credit Number " <<endl;
			cout<<"3) Delete Card with respect to Expiration Date "<<endl;
			cout<<"4) Exit "<<endl <<endl;
			cout<<"Please choose option from the menu: ";
			cin>> choice;
		}
		/*End: code taken from ozgeoneyman_Oneyman_Ozge_hw1.cpp and updated */



		if (choice==1) //display list
		{
			printinglist(head);  //printing the linked list
			if (head==NULL)
			{
				cout<<"List is empty!"<<endl;  //no node left or the file is empty
			}
			cout<<endl;
			cout<<"1) Display List "<<endl;
			cout<<"2) Card Search via Credit Number " <<endl;
			cout<<"3) Delete Card with respect to Expiration Date "<<endl;
			cout<<"4) Exit "<<endl <<endl;

			cout<<"Please choose option from the menu: ";
			cin>> choice;
			cout<<endl;
		}
		else if (choice==2) //card search
		{
			cout<<"Please enter the credit card number: ";
			cin>> num;
			bool check= cardnumcheck(num); //cardnum is in valid format or not
			while (check==false)
			{
				cout<<"Invalid format! "<<endl;
				cout<<"Please enter the credit card number: ";
				cin>> num;
				check= cardnumcheck(num);
			}
			cardsearch(head, num); //finding the valid card
			cout<<endl;
			cout<<"1) Display List "<<endl;
			cout<<"2) Card Search via Credit Number " <<endl;
			cout<<"3) Delete Card with respect to Expiration Date "<<endl;
			cout<<"4) Exit " <<endl<<endl;

			cout<<"Please choose option from the menu: ";
			cin>> choice;
			cout<<endl;
		}
		else if (choice==3) //delete cards
		{
			int pmonth,pyear;
			bool check2;
			cout<<"Please enter month and year: ";
			cin>> pmonth>> pyear;
			checkmonth(pmonth); //checking for valid dates or not

			/*Begin: code taken from ozgeoneyman_Oneyman_Ozge_hw1.cpp and updated */
			while (checkmonth(pmonth)==false || cin.fail())
			{
				cin.clear();
				cin.ignore(INT_MAX,'\n');
				cout<<"Invalid Date! "<<endl;
				cout<<"Please enter month and year: ";
				cin>> pmonth>> pyear;
				checkmonth(pmonth);

			}
			/*End: code taken from ozgeoneyman_Oneyman_Ozge_hw1.cpp and updated */

			check2=searchmonthyear(head, pmonth, pyear);  //checking a node with that date is in the list or not

			if (check2==false)
			{
				cout<< "There is no node with expiration date "<< pmonth<< " "<<pyear<<", nothing deleted! "<<endl;
				cout<<endl;
				cout<<"1) Display List "<<endl;
				cout<<"2) Card Search via Credit Number " <<endl;
				cout<<"3) Delete Card with respect to Expiration Date "<<endl;
				cout<<"4) Exit " <<endl<<endl;

				cout<<"Please choose option from the menu: ";
				cin>> choice;
				cout<<endl;
			}
			else
			{
				if (head==NULL)
				{
					cout<<"List is empty! "<<endl; //no node is there
				}
				else
				{
					deletingnode(head, pmonth, pyear); //deleting the node with the date which user given
				}
				cout<<endl;
				cout<<"1) Display List "<<endl;
				cout<<"2) Card Search via Credit Number " <<endl;
				cout<<"3) Delete Card with respect to Expiration Date "<<endl;
				cout<<"4) Exit "<<endl <<endl;

				cout<<"Please choose option from the menu: ";
				cin>> choice;
				cout<<endl;
			}
		}
	}
	if (choice== 4)//for no memory leak
	{
		clearlist(head); //deleting the whole list
		cout<< "Terminating..."<<endl;
	}

}
