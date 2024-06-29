#include"Header.h"
void push(int x, stack*& tail) {
	node* newNode = new node;
	newNode->data = x;
	newNode->next = nullptr;
	if (tail == nullptr)
	{
		tail = new stack;
		tail->tail = newNode;
	}
	else
	{
		newNode->next = tail->tail;
		tail->tail = newNode;
	}
}
void pop(stack*& tail)
{
	if (tail == nullptr) {
		cout << "Stack is already empty." << endl;
		return;
	}

	node* currentNode = tail->tail;
	tail->tail = currentNode->next;
	delete currentNode;
};
void PrintStack(stack* tail) {
	if (tail == nullptr)
	{
		cout << "Stack is empty." << endl;
		return;
	}

	node* currentNode = tail->tail;
	while (currentNode != nullptr)
	{
		cout << currentNode->data << " ";
		if (currentNode->next != nullptr)
			currentNode = currentNode->next;
		else 
			break;
	}

	cout << endl;
}
void clear(stack*& tail)
{
	if (tail == NULL)
		return;
	while (tail->tail != nullptr)
	{
		pop(tail);
	}
}

void WriteToFile(stack* tail)
{
	fstream file("file.txt");
	if (!file.is_open())
	{
		cout << "File opening error" << endl;
		return;
	}
	if (tail == nullptr)
	{
		cout << "Stack is empty." << endl;
		return;
	}

	node* currentNode = tail->tail;
	while (currentNode != nullptr)
	{
		file << currentNode->data << endl;
		currentNode = currentNode->next;
	}
	file.close();
}
void ReadFromFile(stack* tail)
{
	fstream file("file.txt");
	if (!file.is_open())
	{
		cout << "File opening error" << endl;
		return;
	}
	clear(tail);
	string line;
	stack* temp = nullptr;
	while(getline(file, line))
	{
		if (line.empty())
			break;
		for (int i = 0; i < line.length(); i++)
		{
			if (!isdigit(line[i]) && line[i] != '-')
			{
				cout << "Incorrect file type" << endl;
				clear(tail);
				return;
			}
		}
		push(stoi(line), temp);
	}
	if (temp != nullptr) {
		node* currentNode = temp->tail;
		while (currentNode != nullptr) {
			push(currentNode->data, tail);
			currentNode = currentNode->next;
		}
	}
	else
	{
		cout << "File is empty" << endl;
		return;
	}

};
void DivideStack(stack*&tail)	{
	if (tail == nullptr)
	{
		cout << "Stack is empty" << endl;
		return;
	}
	stack* posStack = nullptr;
	stack* negStack = nullptr;
	node* currentNode = tail->tail;
	while (currentNode != nullptr)
	{
		if (currentNode->data >= 0)
			push(currentNode->data, posStack);
		else
			push(currentNode->data, negStack);
		currentNode = currentNode->next;
	}
	if (posStack == nullptr)
		cout << "There's no positive nums in the stack" << endl;
	else
	{
		cout << "Stack with positive nums and 0-s: ";
		PrintStack(posStack);
		cout << endl;
	}
	if (negStack == nullptr)
		cout << "There's no negative nums in the stack" << endl;
	else
	{
		cout << "Stack with negative nums: ";
		PrintStack(negStack);
		cout << endl;
	}
	return;
}
