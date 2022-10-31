
/OZGE ONEYMAN 24906

#include <iostream>
#include <string>
#include <fstream>
#include <vector>

using namespace std;

struct xy					// struct for keeping the x and y coordinates
{
	int x;
	int y;
};

bool inputCheck(ifstream& f)
{
	string name;
	cout << "Please enter the input file name: " ;
	cin >> name;

	f.open(name.c_str());
	while(f.fail())
	{
		cout << "Couldn't open file. Please enter again: ";
		cin >> name;
		f.open(name.c_str());
	}
	string line;
	int N;
	f >> N;						// for the matrix's long
	getline(f, line);	

	int rowCount = 0;
	while(getline(f, line))
	{
		rowCount++;
	}

	if(rowCount != N + 2)
		return false;

	f.clear(); f.seekg(0);
	getline(f,line);
	for(int i = 0; i < N; i++)
	{
		getline(f,line);

		if(line.length() != N)
			return false;
		for(int j = 0 ; j < N; j++){
			if(line.at(j) < 'A' || line.at(j) > 'Z')					// checking the letters are upper or not
				return false;
		}
	}
	f.clear();
	f.seekg(0);

	return true;
}

int getN(ifstream &f) // reading the N value, matrix's length
{
	int N;
	f >> N;
	string s;
	getline(f,s);
	return N;
}

vector<vector<char>> getMatrix(ifstream &f, int N)				//function for the placing the matrix
{
	vector<vector<char>> matrix(N, vector<char>(N));
	for(int i = 0; i < N; i++)
	{
		string line;
		getline(f,line);
		for(int j = 0; j < N; j++)
			matrix[i][j] = line.at(j);
	}

	string s;
	getline(f,s);
	return matrix;
}

int getM(ifstream &f)					// getting the value of the words length
{
	int M;
	f >> M;
	return M;
}

int exists(const vector<string> &  words, string word)				// checking the word is in the vector or not
{
	for(int i = 0; i < words.size(); i++)
	{
		if(words[i] == word)
			return i;
	}
	return -1;
}

bool xyExists(vector<xy> & xys, int x, int y)
{
	for(int i = 0; i < xys.size(); i++)
	{
		if(xys[i].x == x && xys[i].y == y)
			return true;
	}
	return false;
}

void printResults(vector<string> &words, vector<int> & counts)					//printing the output
{
	for(int i = 0; i < words.size(); i++)
	cout << words[i] << " exists " << counts[i] << " many times." << endl;
}
bool inRange(int x, int y, int N)   // looking the numbers are in the boundries or not
{
	if(x < 0)						//out of the boundary
		return false;
	if(x >= N)							// out of the boundary
		return false;
	if(y < 0)								// out of the boundary
		return false;
	if(y >= N)								// out of the boundary
		return false;

	return true;
}
void process(const vector<vector<char>> & matrix, vector<xy> xys, string word, int N, int M, int x, int y, vector<string> & words, vector<int> & counts)
{
	if(inRange(x,y,N) && !xyExists(xys, x, y))
	{
		word = word + matrix[x][y];
		xy XY;
		XY.x = x;
		XY.y = y;
		xys.push_back(XY);

		if(word.length() == M)				// if length equal to M thats mean we find our words
		{
			int index = exists(words, word);
			if(index != -1)
				counts[index]++;				// counting the number of words 
			else
			{
				words.push_back(word);						// if the word is not it in the matrix we send it
				counts.push_back(1);				
			}
		}
		else
		{
			process(matrix,xys,word,N,M,x, y+1, words, counts);				// recursive functions to finding the words
			process(matrix,xys,word,N,M,x, y-1, words, counts);
			process(matrix,xys,word,N,M,x+1, y, words, counts);
			process(matrix,xys,word,N,M,x-1, y, words, counts);
		}
	}
}



void startProcess(vector<vector<char>> & matrix, int N, int M, vector<string> & words, vector<int> & counts)
{
	vector<xy> xys;
	string word = "";
	for(int i = 0 ; i < N; i++)
		for(int j = 0 ; j < N; j++)
			process(matrix,xys,word,N,M,i,j, words, counts);	
}
int main()
{

	ifstream f;
	if(inputCheck(f))		// for checking the file is correct or not
	{
		int N = getN(f);								// reading integer for matrix's length
		vector<vector<char>> matrix = getMatrix(f, N);						// creating the matrix
		int M = getM(f);									// reading integer for the word's length

		vector<string> words;								// a vector to keep the words
		vector<int> counts;								// numbers of words

		startProcess(matrix,N,M,words,counts);					// finding the word process
		printResults(words, counts);							// outputs
	}
	else
		cout << "Input file is not as expected." << endl;
	return 0;
}
