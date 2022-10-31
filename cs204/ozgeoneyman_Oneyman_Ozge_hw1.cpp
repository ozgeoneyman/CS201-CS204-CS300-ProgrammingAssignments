//OZGE ONEYMAN 24906

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <stdlib.h>
#include <iomanip> //setw(2)


using namespace std;

bool checkxy(int x, int y, int rownum, int colnum)
{
	// input check for the matrix
	if ((x >= 0 && x < rownum) && ( y >= 0 && y < colnum))  //checking the matrix in the range or not
	{
		return true;

	}
	else 
	{
		return false;
	}



}


void printingmatrix(const vector<vector<char>> &matrix)  //printing matrix after reading input
{
	cout<< "Input Matrix:" << endl;
	for (int i = 0; i < matrix.size(); i++)
	{
		for (int k = 0; k < matrix[0].size(); k++)
		{

			cout<< matrix[i][k]<<" ";
		}
		cout<<endl;
	}
}
void printingpath(const vector<vector<char>> &matrix, vector<int> &xvec, vector<int> &yvec, int x, int y)  //printing path for the closed or enclosed area
{
	cout<< x <<setw(2)<< y<<endl;
	for (int i = 0; i < xvec.size(); i++)
	{
		cout<< xvec[i] <<setw(2) <<yvec[i]<<endl;
	}
}
bool path(const vector<vector<char>> &matrix,vector<int> &xvec, vector<int> &yvec, int x, int y,int rownum, int colnum)
{		//path for the matrix 
	bool check=true;
	int count=0;
	int a= matrix.size(), b=matrix[0].size();
	vector<vector<char>> temp(a,vector<char> (b)); //temp vector in order not to go to same point again

	int lastx= x, lasty= y;
	temp[x][y]++;
	if (checkxy(x,y+1,rownum,colnum) && matrix[x][y+1]=='x' && temp[x][y+1]==0 )  //turning right
	{
		temp[x][y+1]++;
		y=y+1;
		xvec.push_back(x);
		yvec.push_back(y);
		count++;

	}
	else if (checkxy(x+1,y,rownum,colnum) && matrix[x+1][y]=='x'&& temp[x+1][y]==0 ) //turning down
	{
		temp[x+1][y]++;						
		x= x+1;
		xvec.push_back(x);
		yvec.push_back(y);
		count++;

	}
	else if (checkxy(x,y-1,rownum,colnum) && matrix[x][y-1]=='x'&& temp[x][y-1]==0 )   //turning left
	{
		temp[x][y-1]++;
		y=y-1;
		xvec.push_back(x);
		yvec.push_back(y);
		count++;
	}
	else if (checkxy(x-1,y,rownum,colnum) && matrix[x-1][y]=='x' && temp[x-1][y]==0 ) //turning up
	{
		temp[x-1][y]++;
		x=x-1;
		xvec.push_back(x);
		yvec.push_back(y);
		count++;
	}
	else    //cannot do anything
	{
		check= false;
	}



	while (((x != lastx) || (y != lasty) )&& check==true)   //until come to start point or cannot be an enclosed area
	{

		if (checkxy(x,y+1,rownum,colnum) && matrix[x][y+1]=='x' && temp[x][y+1]==0 )  //turning right
		{
			temp[x][y+1]++;
			y=y+1;
			xvec.push_back(x);
			yvec.push_back(y);
			count++;
		}
		else if (checkxy(x+1,y,rownum,colnum) && matrix[x+1][y]=='x'&& temp[x+1][y]==0 )	//turning down
		{
			temp[x+1][y]++;						
			x= x+1;
			xvec.push_back(x);
			yvec.push_back(y);
			count++;
		}
		else if (checkxy(x,y-1,rownum,colnum) && matrix[x][y-1]=='x'&& temp[x][y-1]==0 )	//turning left
		{
			temp[x][y-1]++;
			y=y-1;
			xvec.push_back(x);
			yvec.push_back(y);
			count++;
		}
		else if (checkxy(x-1,y,rownum,colnum) && matrix[x-1][y]=='x' && temp[x-1][y]==0 )		//turning down
		{
			temp[x-1][y]++;
			x=x-1;
			xvec.push_back(x);
			yvec.push_back(y);
			count++;
		}
		else
		{ 

			if (((x==lastx && y+1==lasty)||(x+1==lastx && y==lasty)||(x==lastx && y-1==lasty)||(x-1==lastx && y==lasty)) && (count !=1))
			{
				//check if the x and y came to start point
				check=true;
				break;
			}
			else
			{
				check=false;
			}
	
		}

	}
	return check;

}

int main()
{
	int rownum, colnum;
	string file, line;
	ifstream inputfile;
	vector<vector<char>> matrix;

	cout<< "Please enter file name: ";
	cin>> file;
	inputfile.open(file);  

	while (inputfile.fail())
	{
		cout<< "Cannot find a file named " << file<< endl;
		cout<< "Please enter file name: ";
		cin>> file;
		inputfile.open(file);
	}

	while (!(inputfile.eof()))
	{
		getline(inputfile, line);
		stringstream iss(line);

		char ch;
		vector<char> temp;
		//reading the file char by char
		while (iss>> ch)
		{
			temp.push_back(ch);
		}
		matrix.push_back(temp);

	}

	rownum= matrix.size();
	colnum= matrix[0].size();
	bool check = true, check2=true,a=true;
	int count =0, count2=0;
	for (int k = 0; k < rownum && check; k++)		//checking the matrix for symbols
	{
		count=0;
		for (int i = 0; i < matrix[k].size() && check; i++)
		{
			if (matrix[k][i]=='o')
			{
				check= true;
			}
			else if (matrix[k][i]=='x')
			{
				check= true;
			} 
			else
			{
				check= false;
			}
			count++;
		}
		if (a)		//for checking the members of each line is equal with other rows or not
		{
			count2=count;
			a=false;
		}
		if (count2==count && check2)
		{
			check2=true;
		}
		else
		{
			check2=false;
			break;
		}



	}
	if (check != true)
	{
		cout << file <<" includes invalid char(s) "<< endl;
	}
	else if (check2==false)
	{
		cout<< file << " is invalid matrix, does not contain same amount of char each row! "<< endl;
	}
	else
	{
		int x, y;
		printingmatrix(matrix);
		cout<<"Please enter starting coordinates, first row X then column Y: ";
		cin>>x>>y;

		vector<int> xvec;	//for printing x coor.
		vector<int> yvec;	//for printing y coor.
		while (x!= -1 || y!=-1)
		{
			if (cin.fail() || checkxy(x,y,rownum,colnum)==false)
			{
				cin.clear();
				cin.ignore(INT_MAX, '\n');			//for reading string
				cout << "Invalid Coordinates"<< endl<<endl;
				cout<<"Please enter starting coordinates, first row X then column Y: ";
				cin>>x>>y;

			}

			else
			{


				if (matrix[x][y]=='o')	//cannot be start point
				{
					cout<<"This cell is not occupied! "<<endl<<endl;
					cout<<"Please enter starting coordinates, first row X then column Y: ";
					cin>>x>>y;
					xvec.clear();	//clear for each starting point
					yvec.clear();


				}
				else if (path(matrix,xvec, yvec,x, y, rownum,colnum)==true)			//for finding path for closed or enclosed area
				{
					cout<< "Found an enclosed area. The coordinates of the followed path: "<< endl;
					printingpath(matrix, xvec, yvec , x,y);		//printing enclosed path
					cout<<"Please enter starting coordinates, first row X then column Y: ";
					cin>>x>>y;
					xvec.clear();
					yvec.clear();

				}
				else
				{
					cout<< "Cannot found an enclosed area starting with given coordinate. The coordinates of the followed path: " << endl;
					printingpath(matrix,xvec, yvec, x,y);		//printing closed path
					cout<<"Please enter starting coordinates, first row X then column Y: ";
					cin>>x>>y;
					xvec.clear();
					yvec.clear();

				}


			}

		}
		if (x==-1 && y==-1)
		{
			cout<<"Terminating..."<<endl;
		}



	}
}