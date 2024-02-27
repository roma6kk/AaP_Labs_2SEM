#include<iostream>
#include<Windows.h>
#include<string>
#include<fstream>
using namespace std;
int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	string line;
	fstream FILE1("FILE1.txt");
	if (!FILE1.is_open())
	{
		cerr << "Ошибка открытия файла FILE1.txt! " << endl;
		return 1;
	}
	fstream FILE2("FILE2.txt");
	if (!FILE2.is_open())
	{
		cerr << "Ошибка открытия файла FILE1.txt! " << endl;
		return 1;
	}
	while (getline(FILE1, line))
	{
		bool is_num = false;
		for (int i = 0; i < line.length(); i++)
		{
			if (line[i] >= '0' && line[i] <= '9')
			{
				is_num = true;
			}
		}
		if (!is_num)
		{
			FILE2 << line << endl;
		}
	}
	FILE2.seekg(0, ios::beg);
	int A_line_counter = 0;
	while (getline(FILE2, line))
	{
		if (line[0] == 'А' || line[0] == 'A')
		{
			A_line_counter++;
		}
	}
	cout << "Количество строк начинающихся с буквы А: " << A_line_counter << endl;

}