#include <iostream>
#include <string>

using namespace std;

void OperatorApplier(string SourceString , string SearchString)
{
	char Operator = SearchString.at(SearchString.length()-1);
	string ExtractedSearchString = SearchString.substr(0,SearchString.length()-1);
	string ExtractedSourceString = SourceString.substr(0,SourceString.length()-4);

	if (Operator == '+') // find searchstring at the beginning or at the end
	{
		int index= 0, tempindex = 0;
		while(index != -1)
		{
			index = ExtractedSourceString.find(" "); //first find the spaces so that words will be seperated
			string Parsedinput= ExtractedSourceString.substr(0, index); //first word start begining to space

			int length= Parsedinput.length();
			int start= Parsedinput.find(ExtractedSearchString); // is search string in the begining?
			int finish= Parsedinput.rfind(ExtractedSearchString); // is search string in the end)

			int lenSearch = ExtractedSearchString.length();
			
			if (start == 0 ) // if search string in the begining print the output
			{
				cout<< "index: " << tempindex + ExtractedSourceString.find(Parsedinput) << " word: "<< Parsedinput <<endl;
				
			}
			else if (finish !=-1  &&   finish + lenSearch == length) // if searchstring in the end print to output
			{
			cout<< "index: " << tempindex + ExtractedSourceString.find(Parsedinput) + length - ExtractedSearchString.length() << " word: "<< Parsedinput << endl;
			}

		    int indexn = ExtractedSourceString.find(" ",index+1)-index;
			ExtractedSourceString= ExtractedSourceString.substr(index + 1, ExtractedSourceString.length() );		
			tempindex+= length + 1;
	
		}

	}
	else if (Operator == '*') // find searchstring inside anywhere in the source
	{
		int index= 0, tempindex = 0;
		while(index != -1)
		{
			index = ExtractedSourceString.find(" ");
			string Parsedinput= ExtractedSourceString.substr(0, index);

			int length= Parsedinput.length();
			int findsearch= Parsedinput.find(ExtractedSearchString);
			int lenSearch = ExtractedSearchString.length();
			
			if (findsearch != -1 ) // if searchstring occured in the source print the output
			{
				cout<< "index: " << tempindex + findsearch << " word: "<< Parsedinput <<endl;
				
			}
			
		    int indexn = ExtractedSourceString.find(" ",index+1)-index;
			ExtractedSourceString= ExtractedSourceString.substr(index + 1, ExtractedSourceString.length() );		
			tempindex+= length + 1;
	
		}

	}
	else if(Operator == '.') // find the search string at the end of the word
	{
		int index= 0, tempindex = 0;
		while(index != -1)
		{
			index = ExtractedSourceString.find(" ");
			string Parsedinput= ExtractedSourceString.substr(0, index);

			int length= Parsedinput.length();
			int finish= Parsedinput.rfind(ExtractedSearchString);

			int lenSearch = ExtractedSearchString.length();
			
			if (finish !=-1  &&   finish + lenSearch == length) // if searchstring in the end print to output
			{
			cout<< "index: " << tempindex + ExtractedSourceString.find(Parsedinput) + length - ExtractedSearchString.length() << " word: "<< Parsedinput << endl;
			}

		    int indexn = ExtractedSourceString.find(" ",index+1)-index;
			ExtractedSourceString= ExtractedSourceString.substr(index + 1, ExtractedSourceString.length() );		
			tempindex+= length + 1;
	
		}
	}
}


int main()
{
	string SourceString = "",SearchString,temp,KeyOne = "END",KeyTwo = "end", KeyThree= "QUIT", KeyFour= "quit";
	bool CheckForSourceString = true,cont= true ;
	//This program finds the part of the word or phase which you write into source string. You must type END or end to the end of your search string so that your program starts running. In search string, you must type '+'(word start or end with search str.) or '*'(any word containing search str.) or '.'(word ends with search str.) to start the process. And to finish your program you need to write QUIT or quit to the search string.
	cout << "Enter source string: ";

	while (CheckForSourceString == true)
	{
		cin>>temp;
		SourceString =SourceString + temp + " ";

		if (SourceString.find(KeyOne)!=-1 || SourceString.find(KeyTwo)!=-1) 
			CheckForSourceString = false;
	}

	while (cont)
	{
		cout << "Enter search string: " ;
		cin >> SearchString;


		if (SearchString == KeyFour || SearchString==KeyThree) 
			cont = false;

		OperatorApplier(SourceString,SearchString); // find the searchstring in the source string
	}





}
