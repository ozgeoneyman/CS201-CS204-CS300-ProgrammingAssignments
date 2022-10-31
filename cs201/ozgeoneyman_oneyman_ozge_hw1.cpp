#include <iostream>

#include <string>

using namespace std;
void Function4_display(string name,double profit1,double VAT1,double corporatedtax1,double share1,int shareholders,double capitalincrease1,double netprofit1,double netloss1)//this function allows us to print output of all calculation
{
	if (profit1 > 0)
	{
		cout << "Net Profit: " << netprofit1 << " TL." <<endl;
		cout << "VAT: " << VAT1 << " TL." << endl;
		cout << "Corporate Tax: " << corporatedtax1 << " TL." << endl << endl;
		cout << "Capital Increase: "  << capitalincrease1 << " TL." << endl;
		cout << shareholders << " shareholders will have a share of: " << share1 << " TL."<<endl;
	}
	else if (profit1 == 0)
	{
		cout << "Break Even (Profit = 0 TL)" << endl;
		cout << "VAT: " << VAT1 << " TL." << endl;
		cout << "Corporate Tax: 0 TL." << endl << endl;
		cout << "Capital Increase: 0 TL." << endl;
		cout << shareholders << " shareholders will have a share of: 0 TL."<<endl;
	}
	else if (profit1 < 0)
	{
		cout << "Net Loss: " << netloss1 << " TL." << endl;
		cout << "VAT: " << VAT1 << " TL." << endl;
		cout << "Corporate Tax: 0 TL." << endl << endl;
		cout << "Capital Increase: 0 TL." << endl;
		cout << shareholders << " shareholders will have a share of: 0 TL."<<endl;
	}

}

void Function3_operation(string name,double grossincome,double expenses, int  shareholders)//this function allows us to calculate corparated tax, divendend, VAT, profit,net profit, net loss and capital increase.
{
	cout<< endl<<  "*********** " << name << " Financial Report **********"<<endl<<endl;
	double corporatedtax1=0 ;
	double share1 =0;
	double VAT1= grossincome * 0.18;
	double profit1= grossincome - VAT1 - expenses;
	double netloss1 =0;
	double capitalincrease1 =0;
	double netprofit1=0 ;
	double snetprofit1 =0;
	

	if (profit1 > 0)
	{
		if (profit1 <= 10000)
			corporatedtax1 = profit1 * 0.1;
		else if (10000 < profit1 && profit1 <= 25000)
			corporatedtax1 = profit1 * 0.15;
		else if (25000 < profit1 && profit1 <= 50000)
			corporatedtax1 = profit1 * 0.20;
		else if (50000 < profit1)
			corporatedtax1 = profit1 * 0.25;
		netprofit1= profit1 - corporatedtax1;
		capitalincrease1= netprofit1 * 0.5;
		snetprofit1 = netprofit1; //I use another name for netprofit to avoid confusion while doing continuing calculation and printing
		snetprofit1 = netprofit1-capitalincrease1; 
		snetprofit1=snetprofit1*0.85;
		share1= snetprofit1 / shareholders;
		Function4_display(name,profit1,VAT1,corporatedtax1,share1,shareholders,capitalincrease1,netprofit1,netloss1);
		
	}
	else if (profit1 == 0)
	{
		Function4_display(name,profit1,VAT1,corporatedtax1,share1,shareholders,capitalincrease1,netprofit1,netloss1);
	}
	else if (profit1 < 0)
	{
		netloss1= profit1;
		Function4_display(name,profit1,VAT1,corporatedtax1,share1,shareholders,capitalincrease1,netprofit1,netloss1);
	}
}

void Function2_check(string name,double grossincome,double expenses, int  shareholders)//this function allows us to check whether inputs are acceptable or not.
{
	bool check = true;
	if (grossincome <= 0)
	{
		cout <<"Invalid input for gross income (Gross Income must be greater than 0)."<<endl;
		check = false;
	}
	
	if (expenses < 0)
	{
		cout << "Invalid input for expenses (Expenses must be greater than or equal 0)."<<endl;
		check = false;
	}
	if (shareholders < 1)
	{
		cout << "Invalid input for number of shareholders (number of shareholders must be greater than or equal to 1)."<<endl;
		check = false;
	}
		
	if (check == true)
	{
		Function3_operation(name,grossincome, expenses, shareholders);
	}
	else
	{
		cout << "Stopping calculations..."<<endl<<endl;
	}
	
}
void Function1_input(string name, double grossincome,double expenses, int  shareholders )//this function allows us to take inputs from user for first company.
{

	cout << "Please enter the gross income of " << name << ": " ;

	cin >> grossincome ; 

	cout << "Please enter expenses of " << name << ": " ;

	cin >> expenses  ;

	cout << "Please enter the number of shareholders: " ;

	cin >> shareholders ;
	cout<< endl;
	Function2_check(name,grossincome, expenses, shareholders );
}




int main()  //this main function allows us to call function1. this function is nested function that calls other functions. 
{
	
	string name;
	double grossincome = 0, expenses = 0;
	int shareholders = 0; 
	cout << "This accounting program calculates the state taxes and dividends for the company shareholders." << endl<<endl;
	cout << "Please enter the name of the first company: " ;
	cin >> name ;
	Function1_input(name,grossincome,expenses,shareholders);//nested function. if conditions are true it calls function 2 then calls function 3 and finally calls function4 to print all outputs.
	cout<< endl<<endl;
	cout << "Please enter the name of the second company: " ;
	cin >> name ;
	Function1_input(name,grossincome,expenses,shareholders);//nested function. if conditions are true it calls function 2 then calls function 3 and finally calls function4 to print all outputs.


}

