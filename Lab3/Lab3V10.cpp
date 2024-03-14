#include <iostream>
#include <fstream>
#include <string>
#include<Windows.h>
using namespace std;

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	ifstream FILE1("FILE1.txt");
	if (!FILE1.is_open())
	{
		cerr << "Ошибка открытия FILE1.txt!" << endl;
		return 1;
	}
	ofstream FILE2("FILE2.txt");
	if (!FILE2.is_open())
	{
		cerr << "Ошибка открытия FILE2.txt!" << endl;
		return 1;
	}
	string line1;
	string word1, word;
	int end_index;
	getline(FILE1, line1);
	for (int i = 0; i < line1.length(); i++)
	{
		if (line1[i] == ' ' && i != 0)
		{
			end_index = i;
			break;
		}
	}
	word1 = line1.substr(0, end_index);
	string line;
	int start_index;
	bool to_add = true;
	while (getline(FILE1, line))
	{
		for (int i = 0; i < line.length(); i++)
		{
			if (line[i] >= 'A' && line[i] <= 'z')
			{
				start_index = i;
				while (line[i] != ' ' && line[i] != '\0')
				{
					i++;

				}
				end_index = i;
				word = line.substr(start_index, end_index - start_index);
				if (word == word1)
				{
					to_add = false;
				}
			}

		}
		if (to_add)
		{
			FILE2 << line << '\n';
		}
		to_add = true;

	}
	return 0;
}