#include<iostream>
#include<fstream>
#include<string>
using namespace std;
int main()
{
	setlocale(0, "Rus");
	fstream file("file.txt");
	cout << "Введите строку символов: " << endl;
	string line;
	getline(cin, line);
	for (int i = 0; i < line.length(); i++)
	{
		if ((line[i] < '0' || line[i] > '9') && line[i] != ' ')
		{
			cerr << "Строка должна состоять только из цифр или набора цифр!" << endl;
			return 1;
		}
	}
	file << line;
	file.close();
	int counter = 0;
	int min_group = 100;
	int start_index = 0, end_index = 0;
	for (int i = 0; i < line.length() + 1; i++)
	{
		if (line[i] >= '0' && line[i] <= '9')
		{
			counter++;

		}
		else
		{
			if (counter < min_group)
				{
					min_group = counter;
					end_index = i - 1;
					start_index = end_index - min_group + 1;
				}
			counter = 0;
		}
	}
	cout << "Самая короткая группа: ";
	for (int i = start_index; i < end_index + 1; i++)
		cout << line[i];
}