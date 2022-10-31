
//CONSTRUCTER?


#include <string>
using namespace std; 

/*Begin: code taken from DoublyLinkedList.h and updated */
struct creditCardNode
{
	string creditCardNo;

	creditCardNode * next;

	creditCardNode::creditCardNode()
	{}

	creditCardNode::creditCardNode(const string &s, creditCardNode *linknext)
		:creditCardNo(s), next(linknext)
	{}


};

struct expirationNode
{
	int month, year;

	creditCardNode * cHead;
	expirationNode * next;
	expirationNode * prev;

	expirationNode::expirationNode()
	{}

	expirationNode::expirationNode(int m, int y, creditCardNode* ehead, expirationNode* lnext, expirationNode* lprev)
		:cHead(ehead), next(lnext), prev(lprev) 	
	{}


};

/*End: code taken from DoublyLinkedList.h and updated */


class CardList
{
public:

	CardList(); //default constructor that creates an empty list

	
	void AddingCreditcard(string cardnum,int month, int year, creditCardNode*&head);
	

	void insertCard (string creditCardNo, int month, int year);       

	//inserts a new card to the structure in sorted fashion

	void displaycard(creditCardNode* cHead);

	void displayListChronological ();
	//displays entire structure in chronological order

	void displayListReverseChronological ();

	//displays entire structure in reverse chronological order

	void cardnums (string creditCardNo,creditCardNode *cHead,expirationNode *temp,bool &check);

	void cardSearch (string creditCardNo);						

	//displays all of the occurrences of the given card number

	void deletecardnum(creditCardNode* cHead);
	void bulkDelete (int month, int year);
	//deletes all nodes up to and including given expiration date
	void deleteAllcard(creditCardNode* cHead);
	void deleteAll (); //deletes the entire structure



private:

	expirationNode * head;
	expirationNode * tail;
	creditCardNode * cHead;
};







