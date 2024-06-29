#include <fstream>
#include<iostream>
#include <string>
#include<Windows.h>
using namespace std;

const int MAX_CITIZEN = 100;
struct Citizen {
	string FullName;
	string Sex;
	string BirthDate;
	string Address;
};

string removeSpace(string& text) {
	string buffer;
	bool flag = false;
	for (int i = 0; text[i] != 0; i++) {
			while (flag == false && isspace(text[i])) {
				i++;
			}
			flag = true;
			buffer += text[i];
	}

	for (int i = buffer.size() - 1; buffer[i] >= 0; i--) {
		while (isspace(buffer[i])) {
			i--;
		}
		buffer.erase(i + 1);
		break;
	}
	return buffer;
}
bool getDate(string date)
{
	int day, month, year;
	const int DATEFORM = 8;
	if (date.length() != DATEFORM)
	{
		cerr << "Incorrect date entry!" << endl;
		return false;
	}
	for (int i = 0; i < date.length(); i++)
	{
		if (!isdigit(date[i]))
		{
			cerr << "Incorrect date entry!" << endl;
			return false;
		}
	}
	day = stoi(date.substr(0, 2));
	month = stoi(date.substr(2, 2));
	year = stoi(date.substr(4, 4));
	if (year < 1900 || year > 2024)
	{
		cerr << "Incorrect date entry!" << endl;
		return false;
	}
	bool is_leapYear = false;
	if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
	{
		is_leapYear = true;
	}
	if (!is_leapYear)
	{
		if (month == 2 && day >= 29)
		{
			cerr << "Incorrect date entry" << endl;
			return false;
		}
	}
	if (day > 31 || day <= 0)
	{
		cerr << "Incorrect date entry" << endl;
		return false;
	}
	if (month > 12 || month <= 0)
	{
		cerr << "Incorrect date entry" << endl;
		return false;
	}
	if (year == 2024 && month >= 4 && day > 3)
	{
		{
			cerr << "Incorrect date entry!" << endl;
			return false;
		}
	}
}

bool getDate(string date, int& year, int& month, int& day)// Перегрузка функции
{
	const int DATEFORM = 8;
	if (date.length() != DATEFORM)
	{
		cerr << "Incorrect date entry!" << endl;
		return false;
	}
	for (int i = 0; i < date.length(); i++)
	{
		if (!isdigit(date[i]))
		{
			cerr << "Incorrect date entry!" << endl;
			return false;
		}
	}
	day = stoi(date.substr(0, 2));
	month = stoi(date.substr(2, 2));
	year = stoi(date.substr(4, 4));
	if (year < 1900 || year > 2024)
	{
		cerr << "Incorrect date entry!" << endl;
		return false;
	}
}
bool VerFN(string FullName)
{
	int validation_counter = 0;
	for (int j = 0; j < FullName.length(); j++)
	{
		if ((j != 0 && j - 1 == ' ' && FullName[j] == '-') || (FullName[j + 1] == ' ' && FullName[j] == '-'))
		{
			return false;
		}
			if (FullName[j] == ' ')
			{
				validation_counter++;
			}
		if (FullName[j] >= '!' && FullName[j] <= '@' && FullName[j] != '-')
		{
			return false;
		}
		if (validation_counter > 1)
		{
			if (FullName[j] == '-')
			{
				return false;

			}
		}
	}
	if (validation_counter != 2 && validation_counter != 1)
	{
		return false;

	}
	return true;
}
void addCitizen(Citizen Citizens[], int& CitizenCount) {
	if (CitizenCount < MAX_CITIZEN) {
		cout << "Citizen FullName: ";
		cin.ignore();
		getline(cin, Citizens[CitizenCount].FullName);
		if (Citizens[CitizenCount].FullName.length() <= 0)
		{
			cerr << "Input error!" << endl;
			return;
		}
		Citizens[CitizenCount].FullName = removeSpace(Citizens[CitizenCount].FullName);
		if (!VerFN(Citizens[CitizenCount].FullName))
		{
			cerr << "Input error!" << endl;
			return;
		}
		cout << "Enter Sex(f,m): ";
		getline(cin, Citizens[CitizenCount].Sex);
		if (Citizens[CitizenCount].Sex != "f" && Citizens[CitizenCount].Sex != "m")
		{
			cout << "Input error!" << endl;
			return;
		}
		cout << "Enter BirthDate: ";
		cin >> Citizens[CitizenCount].BirthDate;
		if (!getDate(Citizens[CitizenCount].BirthDate))
			return;
		cout << "Enter Address: ";
		cin.ignore();
		getline(cin, Citizens[CitizenCount].Address);
		if (Citizens[CitizenCount].Address.length() <= 0)
		{
			cerr << "Input error!" << endl;
			return;
		}
		CitizenCount++;
	}
	else {
		cout << "The array is full" << endl;
	}
}

void printCitizens(Citizen Citizens[], int CitizenCount) {
	for (int i = 0; i < CitizenCount; i++) {
		cout << "Citizen name: " << Citizens[i].FullName << endl;
		cout << "Sex: " << Citizens[i].Sex << endl;
		cout << "Birth date: " << Citizens[i].BirthDate << endl;
		cout << "Adress: " << Citizens[i].Address << endl;
		cout << endl;
	}
}

void deleteCitizen(Citizen Citizens[], int& CitizenCount) {
	int INyear, year, month, day;
	cout << "Enter Birth year of Citizen to delete: ";
	cin >> INyear;
	for (int i = 0; i <= CitizenCount; i++) {
		getDate(Citizens[i].BirthDate, year, month, day);
		if (year == INyear) {
			for (int j = i; j < CitizenCount - 1; j++) {
				Citizens[j] = Citizens[j + 1];
			}
			CitizenCount--;
		}
	}
}

void searchCitizen(Citizen Citizens[], int CitizenCount) {
	int INyear, year, month, day;
	cout << "Enter Birth year of Citizen to search: ";
	cin >> INyear;
	for (int i = 0; i < CitizenCount; i++) {
		if (!getDate(Citizens[i].BirthDate, year, month, day))
		{
			return;
		}
		if (year == INyear) {
			cout << "Full name: " << Citizens[i].FullName << endl;
			cout << "Sex: " << Citizens[i].Sex << endl;
			cout << "Birth year: " << Citizens[i].BirthDate << endl;
			cout << "Address: " << Citizens[i].Address << endl;
		}
	}
}

void writeToFile(Citizen Citizens[], int CitizenCount) {
	cout << "Adding citizens in Citizens.txt....." << endl;;
	Sleep(1000);
	ofstream fout("Citizens.txt");
	for (int i = 0; i < CitizenCount; i++) {
		fout << "Full name: " << Citizens[i].FullName << endl;
		fout << "Sex: " << Citizens[i].Sex << endl;
		fout << "BirthDate: " << Citizens[i].BirthDate << endl;
		fout << "Address: " << Citizens[i].Address << endl;
		fout << endl;
	}
	fout.close();
}

bool readFromFile(Citizen Citizens[], int& CitizenCount) {
	ifstream file("Citizens.txt");
	if (!file) {
		cout << "Error opening file." << endl;
		return 0;
	}

	CitizenCount = 0;
	string line;
	int lineCount = 0;
	while (getline(file, line)) {
		if (line.empty())
			return 0;
		lineCount++;
		switch (lineCount % 4) {
		case 1:
			if(line.find("Full name:") != string::npos)
			{
				Citizens[CitizenCount].FullName = line.substr(line.find("Full name: ") + 11);
				if (Citizens[CitizenCount].FullName.length() <= 0)
				{
					cerr << "Input error!" << endl;
					return 1;
				}
				Citizens[CitizenCount].FullName = removeSpace(Citizens[CitizenCount].FullName);
				if (!VerFN(Citizens[CitizenCount].FullName))
				{
					cerr << "Input error!" << endl;
					return 1;
				}
				break;
			}
			else 
			{
				cerr << "Incorrect data  format!" << endl;
				return 1;
			}
		case 2:
			if (line.find("Sex:") != string::npos)
			{
				Citizens[CitizenCount].Sex = line.substr(line.find("Sex: ") + 5);
				if (Citizens[CitizenCount].Sex != "f" && Citizens[CitizenCount].Sex != "m")
				{
					cout << "Input error!" << endl;
					return 1;
				}
				break;
			}
			else
			{
				cerr << "Incorrect data  format!" << endl;
				return 1;
			}
		case 3:
			if (line.find("BirthDate:") != string::npos)
			{
				Citizens[CitizenCount].BirthDate = line.substr(line.find("BirthDate: ") + 11);
				if (!getDate(Citizens[CitizenCount].BirthDate))
					return 1;
				break;
			}
			else
			{
				cerr << "Incorrect data  format!" << endl;
				return 1;
			}
		case 0:
			if (line.find("Address:") != string::npos)
			{
				Citizens[CitizenCount].Address = line.substr(line.find("Address: ") + 9);
				if (Citizens[CitizenCount].Address.length() <= 0)
				{
					cerr << "Input error!" << endl;
					return 1;
				}
				CitizenCount++;
				break;
			}
			else
			{
				cerr << "Incorrect data  format!" << endl;
				return 1;
			}
			break;
		}
	}

	file.close();
	cout << "Modified data read from file successfully." << endl;
	return 0;
}

int main() {
	Citizen Citizens[MAX_CITIZEN];
	int CitizenCount = 0;
	int choice;
		do {
			cout << "MENU" << endl;
			cout << "1. Add Citizen" << endl;
			cout << "2. Print all Citizens" << endl;
			cout << "3. Delete Citizen" << endl;
			cout << "4. Search by year" << endl;
			cout << "5. Write to file" << endl;
			cout << "6. Read from file" << endl;
			cout << "7. Exit" << endl;
			cout << "Enter your choice: ";
			if (!(cin >> choice) || choice == 0 || cin.get() != '\n')
			{
				cerr << "Input error!" << endl;
				cin.clear();
				cin.sync();
				break;
			}
			switch (choice) {
			case 1:
				addCitizen(Citizens, CitizenCount);
				break;
			case 2:
				printCitizens(Citizens, CitizenCount);
				break;
			case 3:
				deleteCitizen(Citizens, CitizenCount);
				break;
			case 4:
				searchCitizen(Citizens, CitizenCount);
				break;
			case 5:
				writeToFile(Citizens, CitizenCount);
				break;
			case 6:
				if(readFromFile(Citizens, CitizenCount))
				{
					return 1;
				}
				else
				{
					break;
				}
			case 7:
				break;
			default:
				cout << "Invalid choice" << endl;
			}
		} while (choice != 7);

		return 0;
}