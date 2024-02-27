#include<iostream>// Вариант 2
#include<fstream>
#include<string>
#include<Windows.h>
using namespace std;
int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	ifstream File1("File1.txt");
	if (!File1.is_open())
	{
		cerr << "Ошибка открытия File1.txt!" << endl;
		return 1;
	}
	fstream File2("File2.txt");
	if (!File2.is_open())
	{
		cerr << "Ошибка открытия File2.txt!" << endl;
		return 1;
	}
	string line;
	int word_count = 0;
	while (getline(File1, line))
	{
		if (line[0] == 'A' || line[0] == 'Р')// Второе условие создано для определния русской буквы А
		{
			File2 << line << endl;
			for(int i = 0 ; i < line.length(); i++)
			{
				if (line[i] != ' ' && (line[i + 1] == ' ' || line[i + 1] == '\0'))
					word_count++;
			}
		}
	}
	for (int i = 0; i < line.length(); i++)
	{

	}
	cout << "Количество слов в File2: " << word_count;
}