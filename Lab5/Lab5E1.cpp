#include <iostream>
#include <string>
#include <sstream>
#include <Windows.h>
#include <limits>

using namespace std;

#define DATA_INPUT_ERROR "AddEmployee: Data input error"

enum Position { MANAGER, ENGINEER, TECHNICIAN };

struct Date {
    unsigned int day : 5;   // Битовое поле для дня (0-31)
    unsigned int month : 4; // Битовое поле для месяца (0-15)
    unsigned int year : 12; // Битовое поле для года (0-4095)
};

struct Employee {
    string fullName;
    string education;
    string specialization;
    string department;
    Position position;
    float salary;
    Date employmentDate;
};

bool isFloat(const string& input) {
    istringstream iss(input);
    float value;
    return (iss >> value) && (iss.eof());
}

bool data_input_error = false;

istream& operator>>(istream& input, Date& date) {
    int day, month, year;
    input >> day >> month >> year;
    try {
        if (day >= 0 && day <= 31 && month >= 0 && month <= 12 && year >= 1900 && year <= 2024) {
            date.day = day;
            date.month = month;
            date.year = year;
        }
        else {
            throw invalid_argument("Data input error");
        }

        bool is_leapYear = false;
        if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
            is_leapYear = true;
        }

        if (!is_leapYear) {
            if (month == 2 && day >= 29) {
                data_input_error = true;
                cerr << "Data input error" << endl;
                return input;
            }
        }

        if (day > 31 || day <= 0) {
            data_input_error = true;
            cerr << "Data input error" << endl;
            return input;
        }

        if (month > 12 || month <= 0) {
            data_input_error = true;
            cerr << "Data input error" << endl;
            return input;
        }

        if (year == 2024 && month >= 5 && day > 7) {
            data_input_error = true;
            cerr << "Data input error" << endl;
            return input;
        }

    }
    catch (const exception& e) {
        data_input_error = true;
        cerr << "Data input error" << endl;
        return input;
    }

    return input;
}

const int MAX_EMPLOYEES = 100;
Employee employees[MAX_EMPLOYEES];
int numEmployees = 0;

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

bool VerFN(string FullName) {
    int validation_counter = 0;
    for (int j = 0; j < FullName.length(); j++) {
        if ((j != 0 && j - 1 == ' ' && FullName[j] == '-') || (FullName[j + 1] == ' ' && FullName[j] == '-')) {
            return false;
        }
        if (FullName[j] == ' ') {
            validation_counter++;
        }
        if (!isalnum(FullName[j]) && !isspace(FullName[j]) && !ispunct(FullName[j])) { 
            return false;
        }
        if (validation_counter > 1) {
            if (FullName[j] == '-') {
                return false;
            }
        }
    }
    if (validation_counter != 2 && validation_counter != 1) {
        return false;
    }
    return true;
}

void addEmployee()
{
    if (numEmployees >= MAX_EMPLOYEES)
    {
        cout << "Максимальное количество работников достигнуто." << endl;
        return;
    }

    Employee newEmployee;

    cout << "Введите Ф.И.О. работника: ";
    getline(cin, newEmployee.fullName);
    if (newEmployee.fullName.length() <= 0)
    {
        cerr << "Input error!" << endl;
        return;
    }
    newEmployee.fullName = removeSpace(newEmployee.fullName);
    if (!VerFN(newEmployee.fullName))
    {
        cerr << "Input error!" << endl;
        return;
    }
    cout << "Введите образование работника: ";
    getline(cin, newEmployee.education);
    if (newEmployee.education.length() < 1)
    {
        cout << "Input error" << endl;
        cin.clear();
        cin.ignore(32767, '\n');
        return;
    }
    for(int i = 0; i < newEmployee.education.length(); i++)
    {
        if ((newEmployee.education[i] < 65 || newEmployee.education[i] > 122) && newEmployee.education[i] != ' ' && newEmployee.education[i] != '-')
        {
            cout << "Input error" << endl;
            cin.clear();
            cin.ignore(32767, '\n');
            return;
        }
    }
    cout << "Введите специальность работника: ";
    getline(cin, newEmployee.specialization);
    if (newEmployee.specialization.length() < 1)
    {
        cout << "Input error" << endl;
        cin.clear();
        cin.ignore(32767, '\n');
        return;
    }
    for (int i = 0; i < newEmployee.specialization.length(); i++)
    {
        if ((newEmployee.specialization[i] < 65 || newEmployee.specialization[i] > 122) && newEmployee.specialization[i] != ' ' && newEmployee.specialization[i] != '-')
        {
            cout << "Input error" << endl;
            cin.clear();
            cin.ignore(32767, '\n');
            return;
        }
    }
    cout << "Введите подразделение работника: ";
    getline(cin, newEmployee.department);
    if (newEmployee.department.length() < 1)
    {
        cout << "Input error" << endl;
        cin.clear();
        cin.ignore(32767, '\n');
        return;
    }
    for (int i = 0; i < newEmployee.department.length(); i++)
    {
        if ((newEmployee.department[i] < 65 || newEmployee.department[i] > 122) && newEmployee.department[i] != ' ' && newEmployee.department[i] != '-')
        {
            cout << "Input error" << endl;
            cin.clear();
            cin.ignore(32767, '\n');
            return;
        }
    }
    cout << "Выберите должность работника (0 - Менеджер, 1 - Инженер, 2 - Техник): ";
    int positionChoice;
    if (!(cin >> positionChoice) || (positionChoice != 0 && positionChoice != 1 && positionChoice != 2) || cin.get() != '\n')
    {
        cout << "Input error" << endl;
        cin.clear();
        cin.ignore(32767, '\n');
        return;
    }
    newEmployee.position = static_cast<Position>(positionChoice);

    cout << "Введите оклад работника: ";
    string salaryInput;
    getline(cin, salaryInput);

    if (!isFloat(salaryInput)) {
        cerr << "Input error" << endl;
        return;
    }

    newEmployee.salary = stof(salaryInput);
    if (newEmployee.salary < 0) {
        cerr << "Input error" << endl;
        return;
    }
    cout << "Введите дату поступления на предприятие (день месяц год): ";
        Date employmentDate;
        cin >> employmentDate;
        if (data_input_error)
        {
            cin.clear();
            cin.ignore(32767, '\n');
            data_input_error = false;
            return;
        }
        if (cin.fail())
        {
            cout << "Data input error" << endl;
            cin.clear();
            cin.ignore(32767, '\n');
            return;
        }

        newEmployee.employmentDate = employmentDate;
        employees[numEmployees] = newEmployee;
        numEmployees++;


    cout << "Работник успешно добавлен." << endl;
}

void printEmployees()
{
    if (numEmployees == 0)
    {
        cout << "Нет данных о работниках." << endl;
        return;
    }

    cout << "Информация о работниках:" << endl;
    for (int i = 0; i < numEmployees; i++)
    {
        cout << "Работник #" << i + 1 << endl;
        cout << "Ф.И.О.: " << employees[i].fullName << endl;
        cout << "Образование: " << employees[i].education << endl;
        cout << "Специальность: " << employees[i].specialization << endl;
        cout << "Подразделение: " << employees[i].department << endl;
        cout << "Должность: ";
        switch (employees[i].position)
        {
        case MANAGER:
            cout << "Менеджер" << endl;
            break;
        case ENGINEER:
            cout << "Инженер" << endl;
            break;
        case TECHNICIAN:
            cout << "Техник" << endl;
            break;
        }
        cout << "Оклад: " << employees[i].salary << endl;
        cout << "Дата поступления на предприятие: " << employees[i].employmentDate.day << "."
            << employees[i].employmentDate.month << "." << employees[i].employmentDate.year << endl;
        cout << endl;
    }
}

void deleteEmployee(int index)
{
    if (index < 0 || index >= numEmployees)
    {
        cout << "Неверный индекс работника." << endl;
        return;
    }

    for (int i = index; i < numEmployees - 1; i++)
    {
        employees[i] = employees[i + 1];
    }

    numEmployees--;

    cout << "Работник успешно удален." << endl;
}
bool isLeapYear(int year)
{
    if (year % 4 != 0) {
        return false;
    }
    else if (year % 100 != 0) {
        return true;
    }
    else if (year % 400 != 0) {
        return false;
    }
    else {
        return true;
    }
}
int CountDay(int day, int month, int year)
{
    int daysInMonth[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    int dayOfYear = 0;

    for (int i = 0; i < month - 1; i++)
    {
        dayOfYear += daysInMonth[i];
    }

    if (month > 2 && isLeapYear(year))
    {
        dayOfYear++;
    }

    dayOfYear += day;

    return dayOfYear;
}
void searchEmployee() {
    int minWorkExperience;
    cout << "Введите минимальный стаж работы (в годах): ";
    cin >> minWorkExperience;
    int workExperience;
    bool found = false;
    for (int i = 0; i < numEmployees; i++) {
        if (CountDay(employees[i].employmentDate.day, employees[i].employmentDate.month, employees[i].employmentDate.year) >= CountDay(7, 5, 2024) && employees[i].employmentDate.year != 2024)
            workExperience = 2024 - employees[i].employmentDate.year - 1;
        else
            workExperience = 2024 - employees[i].employmentDate.year;
        if (workExperience >= minWorkExperience) {
            cout << "Ф.И.О.: " << employees[i].fullName << endl;
            cout << "Образование: " << employees[i].education << endl;
            cout << "Специальность: " << employees[i].specialization << endl;
            cout << "Подразделение: " << employees[i].department << endl;
            cout << "Должность: ";
            switch (employees[i].position) {
            case MANAGER:
                cout << "Менеджер" << endl;
                break;
            case ENGINEER:
                cout << "Инженер" << endl;
                break;
            case TECHNICIAN:
                cout << "Техник" << endl;
                break;
            }
            cout << "Оклад: " << employees[i].salary << endl;
            cout << "Дата поступления на предприятие: " << employees[i].employmentDate.day << "."
                << employees[i].employmentDate.month << "." << employees[i].employmentDate.year << endl;

            found = true;
        }
    }

    if (!found) {
        cout << "Сотрудники с заданным стажем работы не найдены." << endl;
    }
}
void showMenu()
{
    int choice;

    do
    {
        cout << "Меню:" << endl;
        cout << "1. Добавить работника" << endl;
        cout << "2. Вывести информацию о работниках" << endl;
        cout << "3. Удалить работника" << endl;
        cout << "4. Найти работника" << endl;
        cout << "5. Выход" << endl;
        cout << "Выберите действие: " << endl;
        if (!(cin >> choice) || cin.get() != '\n')
        {
            cout << "Input error" << endl;
            cin.clear();
            cin.ignore(32767, '\n');
            continue;
        }
        switch (choice)
        {
        case 1:
            addEmployee();
            break;
        case 2:
            printEmployees();
            break;
        case 3:
            int index;
            cout << "Введите индекс работника для удаления: ";
            cin >> index;
            cin.ignore(); 
            deleteEmployee(index - 1);
            break;
        case 4:
            searchEmployee();
            break;
        case 5:
            cout << "Выход из программы." << endl;
            break;
        default:
            cout << "Неверный выбор. Попробуйте снова." << endl;
            break;
        }

        cout << endl;
    } while (choice != 5);
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    showMenu();

    return 0;
}