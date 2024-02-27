#include<iostream>// Вариант 3
#include<fstream>
#include<string>
#include<Windows.h>
using namespace std;
int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int k, line_counter = 0;
	string line;
	cout << "Введите строку к: " << endl;
	cin >> k;
	ifstream File1("File1.txt");
	if (!File1.is_open())
	{
		cerr << "Ошибка открытия файла File1.txt! " << endl;
		return 1;
	}
	fstream File2("File2.txt");
	if (!File2.is_open())
	{
		cerr << "Ошибка открытия файла File2.txt!" << endl;
		return 1;
	} 
	string vow_letters = "АаЯяУуЮюОоЕеЁёэЭи";
	unsigned int vow_letters_counter = 0;
	while (getline(File1, line))
	{
		line_counter++;
		if (line_counter >= k && line_counter <= k + 3)
		{
			File2 << line << endl;
			for (int i = 0; i < line.length(); i++)
			{
				for (int j = 0; j < vow_letters.length(); j++)
				{
					if (line[i] == vow_letters[j])
					{
						vow_letters_counter++;
						break;
					}
				}
			}
		}
	}
	File1.close();
	cout << "Количество гласных букв в File2.txt: " << vow_letters_counter << endl;
	File2.close();
}