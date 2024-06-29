// Подключение заголовочного файла "Tree.h".
#include "Tree.h"

// Подключение заголовочного файла <iostream>.
#include <iostream>

// Функция Хеш-функции, которая принимает ключ, размер таблицы и параметр p.
int HashFunction(int key, int size, int p)
{
	return (p + key) % size;
}

// Функция Next_hash, которая принимает хеш-код, размер таблицы и параметр p.
int Next_hash(int hash, int size, int p)
{
	// Вариант 1 функции Next_hash.
	return (hash + 5 * p + 3 * p * p) % size;
}

// Функция create для создания нового объекта хеш-таблицы с заданным размером и указателем на функцию getKey.
Object create(int size, int(*getkey)(void*))
{
	return *(new Object(size, getkey));
}

// Конструктор для объекта хеш-таблицы, который принимает размер и указатель на функцию getKey.
Object::Object(int size, int(*getkey)(void*))
{
	// Инициализация количества элементов и размера таблицы.
	N = 0;
	this->size = size;
	// Указатель на функцию getKey.
	this->getKey = getkey;

	// Выделение памяти для массива данных и инициализация его значениями NULL.
	this->data = new void* [size];
	for (int i = 0; i < size; ++i)
		data[i] = NULL;
}

// Функция insert для вставки элемента в хеш-таблицу.
bool Object::insert(void* d)
{
	bool b = false;
	// Проверка, что количество элементов не превышает размер таблицы.
	if (N != size)
		// Поиск пустого слота в таблице для вставки элемента.
		for (int i = 0, t = getKey(d), j = HashFunction(t, size, 0);
			i != size && !b;  j = Next_hash(j, size, ++i))
			if (data[j] == NULL || data[j] == DEL)
			{
				// Вставка элемента в найденный слот.
				data[j] = d;
				N++;
				b = true;
			}
	return b;
}

// Функция searchInd для поиска индекса элемента в хеш-таблице по ключу.
int Object::searchInd(int key)
{
	// Инициализация индекса t и флага b.
	int t = -1;
	bool b = false;
	// Проверка, что таблица не пуста.
	if (N != 0)
		// Поиск элемента в таблице по ключу.
		for (int i = 0, j = HashFunction(key, size, 0); data[j] != NULL && i != size && !b; j = HashFunction(key, size, ++i))
			if (data[j] != DEL)
				if (getKey(data[j]) == key)
				{
					t = j; b = true;
				}
	return t;
}

// Функция search для поиска элемента в хеш-таблице по ключу.
void* Object::search(int key)
{
	// Поиск индекса элемента в таблице.
	int t = searchInd(key);
	// Возврат элемента, если он найден, и NULL в противном случае.
	return(t >= 0) ? (data[t]) : (NULL);
}

// Функция deleteByKey для удаления элемента из хеш-таблицы по ключу.
void* Object::deleteByKey(int key)
{
	// Поиск индекса элемента в таблице по ключу.
	int i = searchInd(key);
	// Сохранение ссылки на элемент в переменную t.
	void* t = data[i];

	// Если элемент найден, помечаем его как удаленный и уменьшаем количество элементов в таблице.
	if (t != NULL)
	{
		data[i] = DEL;
		N--;
	}

	// Возврат ссылки на удаленный элемент.
	return t;
}

// Функция deleteByValue для удаления элемента из хеш-таблицы по значению.
bool Object::deleteByValue(void* d)
{
	// Удаление элемента из таблицы по ключу, полученному с помощью функции getKey.
	return(deleteByKey(getKey(d)) != NULL);
}

// Функция scan для применения заданной функции к каждому элементу в хеш-таблице.
void Object::scan(void(*f)(void*))
{
	// Обход всех элементов в таблице.
	for (int i = 0; i < this->size; i++)
	{
		// Вывод информации о текущем элементе.
		std::cout << " Элемент" << i;
		if ((this->data)[i] == NULL)
			std::cout << " пусто" << std::endl;
		else
			if ((this->data)[i] == DEL)
				std::cout << " удален" << std::endl;
			else
				f((this->data)[i]);
	}
}
