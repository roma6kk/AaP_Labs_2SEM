#include <iostream>
#include <fstream>
	using namespace std;
	const unsigned int NAME_SIZE = 30;
	const unsigned int CITY_SIZE = 20;
	struct Address
	{
		char name[NAME_SIZE];
		char city[CITY_SIZE];
		Address* next;
		Address* prev;
	};
	void deleteDouble(Address** phead, Address** plast)
	{
		Address* current = *phead;

		while (current != nullptr)
		{
			Address* check = current->next;
			while (check != nullptr)
			{
				if (strcmp(current->name, check->name) == 0 || strcmp(current->city, check->city) == 0)
				{
					Address* temp = check;
					check = check->next;

					if (temp->prev != nullptr)
						temp->prev->next = temp->next;
					else
						*phead = temp->next;

					if (temp->next != nullptr)
						temp->next->prev = temp->prev;
					else
						*plast = temp->prev;

					delete temp;
				}
				else
				{
					check = check->next;
				}
			}

			current = current->next;
		}
	}
	int menu(void)
	{
		char s[80];  int c;
		cout << endl;
		cout << "1. Ввод имени" << endl;
		cout << "2. Удаление имени" << endl;
		cout << "3. Вывод на экран" << endl;
		cout << "4. Поиск" << endl;
		cout << "5. Удалить повторяющиеся элементы" << endl;
		cout << "6. Выход" << endl;
		cout << endl;
		do
		{
			cout << "Ваш выбор: ";
			cin.sync();
			gets_s(s);
			cout << endl;
			c = atoi(s);
		} while (c < 0 || c > 5);
		return c;
	}
	//-----------------------------------------------------------
	void insert(Address * e, Address * *phead, Address * *plast) //Добавление в конец списка
	{
		Address* p = *plast;
		if (*plast == NULL)
		{
			e->next = NULL;
			e->prev = NULL;
			*plast = e;
			*phead = e;
			return;
		}
		else
		{
			p->next = e;
			e->next = NULL;
			e->prev = p;
			*plast = e;
		}
	}
	//-----------------------------------------------------------
	Address* setElement()      // Создание элемента и ввод его значений с клавиатуры 
	{
		Address* temp = new  Address();
		if (!temp)
		{
			cerr << "Ошибка выделения памяти памяти";
			return NULL;
		}
		cout << "Введите имя: ";
		cin.getline(temp->name, NAME_SIZE - 1, '\n');
		cin.ignore(cin.rdbuf()->in_avail());
		cin.clear();
		cout << "Введите город: ";
		cin.getline(temp->city, CITY_SIZE - 1, '\n');
		cin.ignore(cin.rdbuf()->in_avail());
		cin.clear();
		temp->next = NULL;
		temp->prev = NULL;
		return temp;
	}
	//-----------------------------------------------------------
	void outputList(Address * *phead, Address * *plast)      //Вывод списка на экран
	{
		Address* t = *phead;
		while (t)
		{
			cout << t->name << ' ' << t->city << endl;
			t = t->next;
		}
		cout << "" << endl;
	}
	//-----------------------------------------------------------
	void find(char name[NAME_SIZE], Address * *phead)    // Поиск имени в списке
	{
		bool isFounded = false;
		Address* t = *phead;
		while (t)
		{
			if (!strcmp(name, t->name)) 
			{
				cout << t->name << ' ' << t->city << endl;
				isFounded = true;
			}
			t = t->next;
		}
		if (!isFounded)
			cerr << "Имя не найдено" << endl;
	}
	//-----------------------------------------------------------
	void delet(char name[NAME_SIZE], Address** phead, Address** plast) {
		struct Address* t = *phead;
		struct Address* nextNode = NULL;

		while (t) {
			nextNode = t->next;

			if (!strcmp(name, t->name)) {
				if (*phead == t) {
					*phead = t->next;
					if (*phead)
						(*phead)->prev = NULL;
					else
						*plast = NULL;
				}
				else {
					t->prev->next = t->next;
					if (t != *plast)
						t->next->prev = t->prev;
					else
						*plast = t->prev;
				}
				delete t;
				cout << "Элемент удален" << endl;
			}

			t = nextNode;
		}

		if (!(*phead))
			cerr << "Имя не найдено" << endl;
	}
	//-----------------------------------------------------------
	int main(void)
	{
		Address* head = NULL;
		Address* last = NULL;
		setlocale(LC_CTYPE, "Rus");
		while (true)
		{
			switch (menu())
			{
			case 1:  insert(setElement(), &head, &last);
				break;
			case 2: {	  char dname[NAME_SIZE];
				cout << "Введите имя: ";
				cin.getline(dname, NAME_SIZE - 1, '\n');
				cin.ignore(cin.rdbuf()->in_avail());
				cin.sync();
				delet(dname, &head, &last);
			}
				  break;
			case 3:  outputList(&head, &last);
				break;
			case 4: {	  char fname[NAME_SIZE];
				cout << "Введите имя: ";
				cin.getline(fname, NAME_SIZE - 1, '\n');
				cin.ignore(cin.rdbuf()->in_avail());
				cin.sync();
				find(fname, &head);
			}
				  break;
			case 5:
				deleteDouble(&head, &last);
				break;
			case 6:  exit(0);
			default: exit(1);
			}
		}
		return 0;
	}
