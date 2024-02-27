#include<iostream>
#include<fstream>
#include<Windows.h>
#include<string>
using namespace std;
int main()
{
	string line;
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	cout << "Введите строку: " << endl;
	getline(cin, line);
	fstream file("file.txt");
	if (!file.is_open())
	{
		cerr << "Ошибка открытия file.txt! " << endl;
		return 1;
	}
	file << line << '\0';
	file.seekg(0, ios::beg);
	int start_index, end_index;
	int max_syms = 0;
	getline(file, line);
	file.close();
	int sym_counter = 0;
	for (int i = 0; i < line.length(); i++)
	{
		if (line[i] >= 'A' && line[i] <= 'z' || line[i] >= 'А' && line[i] <= 'я')
		{
			while (line[i] != ' ' && line[i] != '\0')
			{
				i++;
				sym_counter++;
			}
		}
		if (sym_counter > max_syms)
		{
			end_index = i - 1;
			start_index = end_index - sym_counter + 1;
			max_syms = sym_counter;
		}
		sym_counter = 0;
			
	}
	cout << "Количество символов самого длинного слова: " << max_syms << endl;
	for (int i = start_index; i <= end_index; i++)
	{
		cout << line[i];
	}
}