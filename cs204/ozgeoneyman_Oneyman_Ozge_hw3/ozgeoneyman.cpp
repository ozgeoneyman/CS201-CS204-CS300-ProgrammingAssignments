#include <iostream>
#include "ozgeoneyman.h"


CardList::CardList()
{
	head=NULL;
	tail=NULL;

}
void CardList::AddingCreditcard(string cardnum,int month, int year, creditCardNode* &cHead)  //for making the credit card nodes
{
	creditCardNode *ctemp=cHead,*prev=NULL;
	bool check=true;

	if (cardnum < cHead->creditCardNo)   //add to beginning
	{
		creditCardNode *pt= new creditCardNode;
		pt->creditCardNo=cardnum;
		pt->next=cHead;
		cHead=pt;

		cout<<cardnum<<" "<<month<<" "<<year<<": inserted to an existing expiration date node"<<endl;
		return;
	}
	while (ctemp!=NULL && check==true)
	{
		if (cardnum == ctemp->creditCardNo)   //if card already inserted
		{

			cout<<cardnum<<" "<<month<<" "<<year<<": this card was already inserted"<<endl;
			check=false;

		}

		else if (cardnum > ctemp->creditCardNo && ctemp->next==NULL)    //add to end
		{
			creditCardNode *pt= new creditCardNode;
			pt->creditCardNo=cardnum;
			pt->next=NULL;
			ctemp->next=pt;
			check=false;
			cout<<cardnum<<" "<<month<<" "<<year<<": inserted to an existing expiration date node"<<endl;
		}
		else if (cardnum< ctemp->creditCardNo)		//add to middle
		{
			creditCardNode *pt= new creditCardNode;
			pt->creditCardNo=cardnum;
			prev->next=pt;
			pt->next=ctemp;
			check=false;
			cout<<cardnum<<" "<<month<<" "<<year<<": inserted to an existing expiration date node"<<endl;
		}
		prev=ctemp;
		ctemp=ctemp->next;
	}

}
void CardList::insertCard(string cardnum,int month, int year)    //for making the doubly linkedlist nodes
{
	expirationNode *temp= head;

	bool check=true;
	if (head==NULL)						//first node
	{
		creditCardNode *pt= new creditCardNode;
		expirationNode *ptr= new expirationNode;
		pt->creditCardNo=cardnum;
		pt->next=NULL;
		ptr->cHead=pt;
		ptr->month=month;
		ptr->year=year;
		ptr->next=NULL;
		ptr->prev=NULL;
		head=ptr;
		tail=ptr;

		cout<<cardnum<<" "<<month<<" "<<year<<": added to a new expiration date node"<<endl;
		return;


	}
	else if (head->year > year || (head->year == year && head->month > month)) //if node will be add to beginning
	{
		creditCardNode *pt= new creditCardNode;
		expirationNode *ptr= new expirationNode;
		pt->creditCardNo=cardnum;
		pt->next=NULL;
		ptr->cHead=pt;
		ptr->month=month;
		ptr->year=year;
		ptr->next=head;
		ptr->prev=NULL;
		temp->prev=ptr;
		head=ptr;
		cout<<cardnum<<" "<<month<<" "<<year<<": added to a new expiration date node"<<endl;
		return;
	}
	else
	{
		while (temp!=NULL && check==true)
		{
			if (year==temp-> year && month==temp->month)			//if node is already there
			{
				AddingCreditcard(cardnum,month,year,temp->cHead);
				check=false;
			}

			else if ((year > temp->year && temp->next==NULL) || (year==temp->year && month > temp->month && temp->next==NULL))
			{
				creditCardNode *pt= new creditCardNode;
				expirationNode *ptr= new expirationNode;
				pt->creditCardNo=cardnum;
				pt->next=NULL;
				ptr->cHead=pt;
				ptr->month=month;
				ptr->year=year;
				ptr->next=NULL;
				ptr->prev=temp;
				temp->next=ptr;
				tail=ptr;
				cout<<cardnum<<" "<<month<<" "<<year<<": added to a new expiration date node"<<endl;
				check=false;
			}
			else if (year > temp->year && year< temp->next->year )
			{
				creditCardNode *pt= new creditCardNode;
				expirationNode *ptr= new expirationNode;				
				pt->creditCardNo=cardnum;
				pt->next=NULL;
				ptr->cHead=pt;
				ptr->month=month;
				ptr->year=year;

				ptr->prev=temp;

				ptr->next=temp->next;
				temp->next->prev=ptr;
				temp->next=ptr;
				cout<<cardnum<<" "<<month<<" "<<year<<": added to a new expiration date node"<<endl;
				check=false;
			}
			else if (year==temp->year && month < temp->month) 
			{
				creditCardNode *pt= new creditCardNode;
				expirationNode *ptr= new expirationNode;				
				pt->creditCardNo=cardnum;
				pt->next=NULL;
				ptr->cHead=pt;
				ptr->month=month;
				ptr->year=year;

				ptr->next=temp;

				ptr->prev=temp->prev;
				temp->prev->next=ptr;
				temp->prev=ptr;				
				cout<<cardnum<<" "<<month<<" "<<year<<": added to a new expiration date node"<<endl;
				check=false;


			}
			else if (year==temp->year && year< temp->next->year && month > temp->month)
			{
				creditCardNode *pt= new creditCardNode;
				expirationNode *ptr= new expirationNode;				
				pt->creditCardNo=cardnum;
				pt->next=NULL;
				ptr->cHead=pt;
				ptr->month=month;
				ptr->year=year;

				ptr->prev=temp;

				ptr->next=temp->next;
				temp->next->prev=ptr;
				temp->next=ptr;


				cout<<cardnum<<" "<<month<<" "<<year<<": added to a new expiration date node"<<endl;
				check=false;


			}
			else if (year==temp->year && year==temp->next->year)
			{
				if (month> temp->month && month< temp->next->month)
				{
					creditCardNode *pt= new creditCardNode;
					expirationNode *ptr= new expirationNode;
					pt->creditCardNo=cardnum;
					pt->next=NULL;
					ptr->cHead=pt;
					ptr->month=month;
					ptr->year=year;

					ptr->prev=temp;

					ptr->next=temp->next;
					temp->next->prev=ptr;
					temp->next=ptr;
					check=false;
					cout<<cardnum<<" "<<month<<" "<<year<<": added to a new expiration date node"<<endl;
				}
				else if (month < temp->month)
				{
					creditCardNode *pt= new creditCardNode;
					expirationNode *ptr= new expirationNode;
					pt->creditCardNo=cardnum;
					pt->next=NULL;
					ptr->cHead=pt;
					ptr->month=month;
					ptr->year=year;

					ptr->next=temp;
					ptr->prev=temp->prev;

					temp->prev->next=ptr;
					temp->prev=ptr;
					check=false;
					cout<<cardnum<<" "<<month<<" "<<year<<": added to a new expiration date node"<<endl;
				}
				else if (month > temp->next->month && temp->next->next==NULL )
				{
					creditCardNode *pt= new creditCardNode;
					expirationNode *ptr= new expirationNode;
					pt->creditCardNo=cardnum;
					pt->next=NULL;
					ptr->cHead=pt;
					ptr->month=month;
					ptr->year=year;
					ptr->next=NULL;
					ptr->prev=head;
					temp->next=ptr;
					tail=ptr;
					check=false;
					cout<<cardnum<<" "<<month<<" "<<year<<": added to a new expiration date node"<<endl;
				}
				else if (year==temp-> year && month==temp->month)
				{
					AddingCreditcard(cardnum,month,year,temp->cHead);
					check=false;
				}			

			}

			temp=temp->next;
		}

	}
}

void CardList::displaycard(creditCardNode* cHead)   //for displaying all nodes
{
	creditCardNode *temp= cHead;
	int count=1;
	while (temp!=NULL)
	{
		cout<<count<<") "<<temp->creditCardNo<<endl;

		temp=temp->next;
		count++;
	}
}
/*Begin: code taken from DoublyLinkedList.cpp and updated */
void CardList::displayListChronological()    //for option 2
{
	expirationNode *temp= head;
	if (head==NULL)
	{
		cout<<"List is empty!"<<endl;

	}
	else
	{
		while (temp!=NULL)
		{
			cout<<"Expiratiton Date: "<<temp->month<<"  "<< temp->year<< endl;
			displaycard(temp->cHead);
			cout<<"-------------------"<<endl;
			temp=temp->next;
		}
	}

}
/*End: code taken from DoublyLinkedList.cpp and updated */

/*Begin: code taken from DoublyLinkedList.cpp and updated */
void CardList::displayListReverseChronological()    //for option 3
{
	expirationNode *temp= tail;
	if (head==NULL)
	{
		cout<<"List is empty!"<<endl;
	}
	else
	{
		while (temp!=NULL)
		{
			cout<<"Expiratiton Date: "<<temp->month<<"  "<< temp->year<< endl;
			displaycard(temp->cHead);
			cout<<"-------------------"<<endl;
			temp=temp->prev;
		}

	}

}
/*End: code taken from DoublyLinkedList.cpp and updated */

/*Begin: code taken from linkedList.cpp and updated */
void CardList::cardnums (string creditCardNo,creditCardNode *cHead,expirationNode *temp,bool &check)   //for option 4
{
	creditCardNode *ptr= cHead;

	while (ptr!=NULL)
	{
		if (ptr->creditCardNo==creditCardNo)
		{
			cout<<"There exists a credit card given number: "<<creditCardNo<< " with expiration date: "<< temp->month<<" "<<temp->year<< endl;

			check=true;
		}
		ptr=ptr->next;
	}
}

void CardList::cardSearch (string creditCardNo)   //for option 4
{
	expirationNode *temp= head;
	bool check=false;

	while (temp!=NULL)
	{
		cardnums(creditCardNo,temp->cHead,temp,check);
		temp=temp->next;
	}

	if (check==false)
	{
		cout<<"There is no credit card with given credit card number: "<< creditCardNo <<endl;
	}
}
/*End: code taken from linkedList.cpp and updated */

void CardList::deletecardnum(creditCardNode* cHead)  //for option 4 
{
	creditCardNode *ptr;

	int count=1;
	while (cHead!=NULL)
	{
		cout<<count<<") "<<cHead->creditCardNo<<endl;
		ptr=cHead;

		cHead=cHead->next;
		delete ptr;
		count++;

	}
}
void CardList::bulkDelete (int month, int year)   //for option 5
{
	int count=0;
	bool check=true;
	expirationNode* temp;

	while (head!=NULL&& check==true)
	{
		if ((head->year< year)||(head->month <=month && head->year <=year))
		{
			cout<<"Node with expiration date "<<head->month<<" "<<head->year<<"  and the following credit cards have been deleted!"<<endl;
			deletecardnum(head->cHead);
			temp=head;
			head=head->next;
			if (head!=NULL)
			{
				head->prev=NULL;

			}

			delete temp;
			count++;
		}

		else
		{
			check=false;
		}

	}
	if (count==0)
	{
		cout<< "There is no node with expiration date "<< month<< " "<<year<<", nothing deleted! "<<endl;

	}

}   

void CardList::deleteAllcard(creditCardNode* cHead)   //for option 5
{
	creditCardNode *ptr;

	while (cHead!=NULL)
	{

		ptr=cHead;
		cHead=cHead->next;
		delete ptr;


	}
}
void CardList::deleteAll()   //for option 6, deleting all nodes
{
	expirationNode* temp;

	while (head!=NULL)
	{

		deleteAllcard(head->cHead);
		temp=head;
		head=head->next;
		if (head!=NULL)
		{
			head->prev=NULL;
		}
		delete temp;

	}


}