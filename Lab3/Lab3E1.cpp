#include<iostream>
#include<string>
#include<fstream>
using namespace std;
int  main()
{
	setlocale(0, "rus");
	string line;
	int ncount = 0;
	fstream File1("File1.txt");
	if (!File1.is_open())
	{
		cerr << "Ошибка открытия файла!" << endl;
	}
	fstream File2("File2.txt");
	if (!File2.is_open())
	{
		cerr << "Ошибка открытия файла!" << endl;
	}
	else
	{
		while (getline(File1, line))
		{
			ncount++;
			if (ncount % 2 == 0)
			{
				File2 << line << "\n";
			}
		}
	}
	File1.close();
	File2.close();
}