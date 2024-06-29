#include<iostream>
#include<string>
#include<fstream>
#include<Windows.h>
using namespace std;

struct list
{
    int data;
    list* next;
};

void AddElement(list*& node, int value)
{
    list* new_node = new list;
    if (cin.fail())
    {
        cout << "Input error" << endl;
        cin.clear();
        cin.ignore(32767, '\n');
        return;
    }
    if (new_node != NULL)
    {
        new_node->data = value;
        new_node->next = node;
        node = new_node;
    }
    else
        cout << "AddElement fail" << endl;
}

void DeleteElement(list*& p)
{
    int value;
    cout << "Enter the number: " << endl;
    cin >> value;
    if (cin.fail())
    {
        cout << "Input error" << endl;
        cin.clear();
        cin.ignore(32767, '\n');
        return;
    }

    list* previous = nullptr;
    list* current = p;

    while (current != NULL && current->data != value)
    {
        previous = current;
        current = current->next;
    }

    if (current != NULL)
    {
        if (previous == nullptr)
        {
            p = current->next;
        }
        else
        {
            previous->next = current->next;
        }
        delete current;
    }
    else
    {
        cout << "The element was not found" << endl;
    }
}

void Print(list* p)
{
    if (p == NULL)
        cout << "List is empty" << endl;
    else
    {
        cout << "List:" << endl;
        while (p != NULL)
        {
            cout << "-->" << p->data;
            p = p->next;
        }
        cout << "-->NULL" << endl;
    }
}

void WriteToFile(list* p)
{
    ofstream frm("File.txt");
    if (frm.fail())
    {
        cout << "\nFile opening error\n";
        return;
    }
    list* temp = p;
    while (temp != NULL)
    {
        frm << temp->data << " ";
        temp = temp->next;
    }
    frm.close();
    cout << "\nList has been successfully wrotten into File.txt\n";
}

void DeleteList(list*& p)
{
    list* current = p;
    while (current != NULL)
    {
        list* next = current->next;
        delete current;
        current = next;
    }
    p = NULL;
}
void ReadFromFile(list*& p)
{
    DeleteList(p);

    ifstream file("File.txt");
    if (!file.is_open())
    {
        cout << "File opening error" << endl;
        return;
    }

    int value;
    list* prev = nullptr;
    list* current = nullptr;
    while (file >> value)
    {
        list* newNode = new list;
        newNode->data = value; 
        newNode->next = nullptr;

        if (prev == nullptr)
        {
            p = newNode; 
        }
        else
        {
            prev->next = newNode;
        }

        prev = newNode;
    }

    file.close();

    cout << "List has been successfully readed from File.txt" << endl;
}
void FindSumPos(list *p)
{
    int sum = 0;
    if (p == NULL)
        cout << "List is empty" << endl;
    else
    {
        while (p != NULL)
        {
            if (p->data > 0)
            {
                sum += p->data;
            }
            p = p->next;
        }
        if (sum == 0)
            cout << "There's no positive elements in the list" << endl;
        else
            cout << "Sum of positive elemnets: " << sum << endl;
    }
}
void FindElement(list* p)
{
    int index;
    int counter = 1;
    cout << "Enter index of the element:" << endl;
    cin >> index;
    if (index <= 0)
    {
        cout << "Incorrect input" << endl;
        return;
    }
    while (p != NULL)
    {
        if (counter == index)
        {
            cout << "Target element: " << p->data << endl;
            return;
        }
        p = p->next;
        counter++;
    }
    cout << "Element not found" << endl;
    return;
}
int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    list* first = NULL;
    int choice;
    int value;
    do
    {
        cout << "1. Add elemnet" << endl;
        cout << "2. Delete element" << endl;
        cout << "3. Print list" << endl;
        cout << "4. Write list into the file" << endl;
        cout << "5. Read list from the file" << endl;
        cout << "6. Find sum of positive elements" << endl;
        cout << "7. Find element by index" << endl;
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
            cout << "Enter the number: " << endl;
            if (!(cin >> value) || cin.get() != '\n')
            {
                cout << "Input error" << endl;
                cin.clear();
                cin.ignore(32767, '\n');
                continue;;
            }
            AddElement(first, value);
            break;
        case 2:
            DeleteElement(first);
            break;
        case 3:
            Print(first);
            break;
        case 4:
            WriteToFile(first);
            break;
        case 5:
            ReadFromFile(first);
            break;
        case 6: 
            FindSumPos(first);
            break;
        case 7:
            FindElement(first);
            break;
        }
    } while (choice != 8);
}