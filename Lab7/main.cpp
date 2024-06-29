#include"Header.h"
stack* myStack = nullptr;
int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    int choice;
    int value;
    do
    {
        cout << "1. Add elemnet" << endl;
        cout << "2. Delete element" << endl;
        cout << "3. Print stack" << endl;
        cout << "4. Write list into the file" << endl;
        cout << "5. Read list from the file" << endl;
        cout << "6. Clear stack" << endl;
        cout << "7. Divide stack" << endl;
        cout << "8. Exit" << endl;
        if (!(cin >> choice) || cin.get() != '\n')
        {
            cout << "Input error" << endl;
            cin.clear();
            cin.ignore(32767, '\n');
            continue;;
        }
        switch (choice)
        {
        case 1:
            cout << "¬ведите число: " << endl;
            if (!(cin >> value) || cin.get() != '\n')
            {
                cout << "Input error" << endl;
                cin.clear();
                cin.ignore(32767, '\n');
                continue;;
            }
            push(value, myStack);
            break;
        case 2:
            pop(myStack);
            break;
        case 3:
            PrintStack(myStack);
            break;
        case 4:
            WriteToFile(myStack);
            break;
        case 5:
            ReadFromFile(myStack);
            break;
        case 6:
            clear(myStack);
            break;
        case 7:
            DivideStack(myStack);
            break;
        default:
            cout << "Input error" << endl;
            continue;
        }
    } while (choice != 8);
}