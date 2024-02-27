#include<iostream>// Вариант 3
#include<Windows.h>
#include<string>
#include<fstream>
using namespace std;
int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	string line;
	fstream file("file.txt");
	if (!file.is_open())
	{
		cerr << "Ошибка открытия file.txt" << endl;
		return 1;
	}
	fstream ofile("ofile.txt");
	if (!ofile.is_open())
	{
		cerr << "Ошибка открытия ofile.txt" << endl;
		return 1;
	}
	cout << "Введите строку: " << endl;
	getline(cin, line);
	file << line << endl;
	file.seekg(0, ios::beg);
	for (int i = 0; i < line.length(); i++)
	{
		if (line[i] >= 'a' && line[i] <= 'Z' || line[i] >= 'а' && line[i] <= 'Я')
		{
			while(line[i] != ' ')
			{
				ofile << line[i];
			}
			ofile << ' ';
		}
	}
	cout << "Сейчас будут выведены слова строчки:  " << endl;
	for (int i = 0; i < line.length(); i++)
	{
		cout << line[i];
	}
	file.close();
	ofile.close();
}
