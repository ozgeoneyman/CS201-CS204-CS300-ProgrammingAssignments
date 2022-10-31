#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include "strutils.h"

using namespace std;
struct res //using for finding typo
{
	int correctnessCount;
	string wname;
};
struct WordInfo //for pool and main text
{
	int WRank, WCorrect, WTypo, WTotal;
	string Word;
};
bool BestCatchTypo(int a, vector<res> & result)
{
	if (0 == result.size())   //when its empty
	{
		return true;   
	}
	else if (a > result[0].correctnessCount)
	{
		result.clear(); // we want best catch
		return true;
	}
	else if (a == result[0].correctnessCount)
	{
		return true;
	}
	return false;
}
int TypoCount(string poolw, string mainw) //finding the correct letters
{
	int correctness=0;

	if (mainw.length() != poolw.length()) // word lengths must be equal
	{
		correctness = -1;
	}
	else
	{
		for (int i = 0; i < poolw.length(); i++)
		{
			if (poolw[i]== mainw[i]) // when the letters equal correctness +++
			{
				correctness++;
			}
		}
		// correctness number must be equal or smaller than the half of the length
		if (poolw.length()-correctness > poolw.length()/2)
		{
			correctness= -1;
		}
		else if (poolw.length()-correctness < poolw.length()/2)
		{
			correctness++;
		}
	}
	return correctness;
}
void SelectSort(vector<WordInfo> & a) // sorting regarding to the total
{
	int j, k, temp, minIndex, numElts = a.size();

	for(k=0; k < numElts - 1; k++)
	{
		minIndex = k; 
		for(j=k+1; j < numElts; j++)
		{
			if (a[j].WTotal < a[minIndex].WTotal)
				minIndex = j; 

		}
		WordInfo temp = a[k]; 
		a[k] = a[minIndex];
		a[minIndex] = temp;
	}
}
void SortAgain(vector<WordInfo> & a) // sorting when the equal total
{
	int j, k, temp, minIndex, numElts = a.size();

	for(k=0; k < numElts - 1; k++)
	{
		minIndex = k; 
		for(j=k+1; j < numElts; j++)
		{ 
			if (a[j].WTotal == a[minIndex].WTotal && a[j].Word > a[minIndex].Word )
			{
				minIndex = j;
			}
		}
		WordInfo temp = a[k]; 
		a[k] = a[minIndex];
		a[minIndex] = temp;
	}
}



int main()
{
	ifstream inFile1, inFile2;
	string PoolFile, MainFile, OutputFile, line, word;

	vector<WordInfo> poolvec, mainvec; 

	cout << "Please enter a filename for the word pool: ";
	cin >> PoolFile;
	inFile1.open(PoolFile.c_str());

	while (inFile1.fail())
	{
		cout << "Cannot open the word pool file."<<endl;
		cout << "Please enter a filename for the word pool: ";
		cin >> PoolFile;
		inFile1.open(PoolFile.c_str());
	}
	while (getline(inFile1,line))
	{
		istringstream issword(line); //for reading word by word
		WordInfo temp;
		while (issword >> word)
		{
			ToLower(word);
			temp.Word= word;
			temp.WCorrect=0;
			temp.WRank=0;
			temp.WTypo=0;
			temp.WTotal=0;
			poolvec.push_back(temp);

		}
	}
	cout << "Please enter a filename for the main text: ";
	cin >> MainFile;
	inFile2.open(MainFile.c_str());

	while (inFile2.fail())
	{
		cout << "Cannot open the main text file."<< endl;
		cout << "Please enter a filename for the main text: ";
		cin >> MainFile;
		inFile2.open(MainFile.c_str());
	}
	while (getline(inFile2,line))
	{
		istringstream issword(line); // for reading word by word
		while (issword >> word)
		{
			ToLower(word);
			vector<res> result;
			for (int i = 0; i < poolvec.size(); i++)
			{
				if (poolvec[i].Word== word) // when the words same in the pool text and the main text
				{
					poolvec[i].WTotal ++;
					poolvec[i].WCorrect ++;
				}
				else 
				{
					int a = TypoCount(poolvec[i].Word, word);

					if (a != -1 && BestCatchTypo(a, result))
					{
						res temp;
						temp.wname=poolvec[i].Word;
						temp.correctnessCount= a;
						result.push_back(temp);

					}

				}
			}

			for (int i = 0; i < result.size(); i++)
			{
				for (int k = 0; k < poolvec.size(); k++)
				{
					if(result[i].wname == poolvec[k].Word)
					{
						poolvec[k].WTypo ++;
						poolvec[k].WTotal ++;	
					}

				}

			}
		}
	}

	cout <<"Please enter a filename for output file: ";
	cin >> OutputFile;
	ofstream inFile3;
	inFile3.open(OutputFile);

	SelectSort(poolvec);
	SortAgain(poolvec);
	inFile3 <<"RANK,WORD,CORRECT,TYPO,TOTAL"<< endl;
	for (int i = 0; i < poolvec.size(); i++)
	{
		poolvec[i].WRank = poolvec.size()-i;
	}
	for (int i = poolvec.size() - 1; i >= 0 ; i--)
	{
		inFile3 <<poolvec[i].WRank<< ",";
		inFile3 <<poolvec[i].Word<< ",";
		inFile3 <<poolvec[i].WCorrect<< ",";
		inFile3 <<poolvec[i].WTypo<< ",";
		inFile3 <<poolvec[i].WTotal <<endl;
	}
	inFile3.close();
	inFile2.close();
	inFile1.close();
	cout << "Results are in the file: " << OutputFile << endl;

	return 0;
}

