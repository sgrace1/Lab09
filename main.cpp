// Spencer Grace
// Lab 09

#include <iostream>
#include <map>
#include <fstream>
#include <string>
#include <algorithm>


using std::cout;
using std::cin;
using std::map;
using std::ifstream;
using std::string;
using std::ofstream;

int main()
{
	ifstream inFile;
	ofstream outFile;
	string text;
	int tally;
	map<string, int> stringMap;

	inFile.open("example.txt");
	outFile.open("output.txt");

	if (!inFile) 
	{
		cout << "Error";
		return 0;
	}

	

	while (inFile >> text) 
	{
		


		if (stringMap.find(text) == stringMap.end())
		{
			stringMap.insert(std::pair<string,int> (text, 1));
		}
		else 
		{
			stringMap.insert(std::pair<string, int>(text, stringMap.find(text)->second++));

		}
	}

	for (map<string,int>::iterator it = stringMap.begin(); it != stringMap.end(); ++it)
	{
		for (int i = it->second; i > 0; i-- ) 
		{

			outFile << it->first << " ";

		}
		
		

	}
	
	outFile.close();
	inFile.close();
	system("PAUSE");
	return 0;

}