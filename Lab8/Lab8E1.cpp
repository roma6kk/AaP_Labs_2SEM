#include <iostream>
using namespace std;

int MAX_QUEUE_SIZE = 100;
int queue_count = 0;
struct Item
{
    Item* next;
    char sym;
};

struct Queue
{
    Item* head;
    Item* tail;
};

void initializeQueue(Queue& q)
{
    q.head = nullptr;
    q.tail = nullptr;
}

bool isQueueEmpty(const Queue& q)
{
    return q.head == nullptr;
}

void enqueue(Queue& q, char symbol)
{
    Item* newItem = new Item;
    newItem->sym = symbol;
    newItem->next = nullptr;

    if (isQueueEmpty(q))
    {
        q.head = newItem;
        q.tail = newItem;
    }
    else
    {
        q.tail->next = newItem;
        q.tail = newItem;
    }
    queue_count++;
}

char dequeue(Queue& q)
{
    if (isQueueEmpty(q))
    {
        cout << "Очередь пуста." << endl;
        return '\0';
    }

    Item* frontItem = q.head;
    char symbol = frontItem->sym;

    q.head = frontItem->next;
    if (q.head == nullptr)
    {
        q.tail = nullptr;
    }
    queue_count--;
    delete frontItem;

    return symbol;
}
void countItems(Queue& q)
{
    int count = 0;
    Item* currentItem = q.head;
    while (currentItem != nullptr)
    {
        count++;
        currentItem = currentItem->next;
    }
    cout << "Количество элементов в очереди: " << count << endl;
}
void printQueue(const Queue& q)
{
    if (isQueueEmpty(q))
    {
        cout << "Очередь пуста." << endl;
        return;
    }

    cout << "Очередь: ";
    Item* currentItem = q.head;
    while (currentItem != nullptr)
    {
        cout << currentItem->sym << " ";
        currentItem = currentItem->next;
    }
    cout << endl;
}

void clearQueue(Queue& q)
{
    while(q.head != nullptr)
        dequeue(q);
    cout << "Очередь успешно очищена" << endl;
}

void getFirstQueueElement(Queue& q)
{
    if (q.head == nullptr)
    {
        cout << "Очередь пуста!" << endl;
        return;
    }
    cout << "Первый элемент очереди: " << q.head->sym << endl;
    return;
}

void menu(Queue& q, char targetSymbol)
{
    int choice;
    char symbol;
    Item* currentItem;
    int count;
    cout << "Введите максимальный размер очереди: " << endl;
    if (!(cin >> MAX_QUEUE_SIZE) || cin.get() != '\n')
    {
        cout << "Input error" << endl;
        cin.clear();
        cin.ignore(32767, '\n');
        return;
    }
    while (true)
    {
        cout << "Меню:" << endl;
        cout << "1. Добавить символ в очередь" << endl;
        cout << "2. Вывести содержимое очереди" << endl;
        cout << "3. Удалить элемент из очереди" << endl;
        cout << "4. Посчитать количество элементов в очереди" << endl;
        cout << "5. Очистить очередь" << endl;
        cout << "6. Получить первый элемент очереди" << endl;
        cout << "0. Выход" << endl;
        cout << "Выберите операцию: ";
        if (!(cin >> choice) || cin.get() != '\n')
        {
            cout << "Input error" << endl;
            cin.clear();
            cin.ignore(32767, '\n');
            continue;
        }
        switch (choice)
        {
        case 0:
            return;
        case 1:
            if (queue_count >= MAX_QUEUE_SIZE)
            {
                cout << "Очередь переполнена!" << endl;
                break;
            }
            cout << "Введите символ: ";
            if (!(cin >> symbol) || cin.get() != '\n')
            {
                cout << "Input error" << endl;
                cin.clear();
                cin.ignore(32767, '\n');
                continue;
            }
            enqueue(q, symbol);
            if (symbol == targetSymbol)
            {
                cout << "Встречен эталонный символ." << endl;
                printQueue(q);
                count = 0;
                currentItem = q.head;
                while (currentItem != nullptr)
                {
                    count++;
                    currentItem = currentItem->next;
                }
                if (count < 2)
                {
                    dequeue(q);
                }
                else
                {
                    dequeue(q);
                    dequeue(q);
                }
                count = 0;
                currentItem = q.head;
                while (currentItem != nullptr)
                {
                    count++;
                    currentItem = currentItem->next;
                }
                cout << "Количество оставшихся элементов в очереди: " << count << endl;
                return;
            }
            break;
        case 2:
            printQueue(q);
            break;
        case 3:
            dequeue(q);
            break;
        case 4:
            countItems(q);
            break;
        case 5: 
            clearQueue(q);
            break;
        case 6:
            getFirstQueueElement(q);
            break;
        default:
            cout << "Неверный выбор." << endl;
        }

        cout << endl;
    }
}

int main()
{
    setlocale(0, "rus");
    Queue queue;
    initializeQueue(queue);
    char targetSymbol;
    do
    {
        cout << "Введите эталонный символ: ";
        if (!(cin >> targetSymbol) || cin.get() != '\n')
        {
            cout << "Input error" << endl;
            cin.clear();
            cin.ignore(32767, '\n');
            continue;
        }
        else
            break;
    } while (true);

    menu(queue, targetSymbol);

    Item* currentItem = queue.head;
    while (currentItem != nullptr)
    {
        Item* nextItem = currentItem->next;
        delete currentItem;
        currentItem = nextItem;
    }

    return 0;
}