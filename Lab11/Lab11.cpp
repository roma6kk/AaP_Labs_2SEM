#include <iostream>
using namespace std;

struct Tree {
    int key;        
    char text[5];   
    int value;
    Tree* Left;
    Tree* Right;
    Tree* isRightChild;
    Tree* Parent;
};

int sum = 0;

Tree* makeTree(Tree* Root); 
Tree* list(int i, char* s); 
Tree* insertElem(Tree* Root, int key, char* s);  
Tree* search(Tree* n, int key);   
Tree* delet(Tree* Root, int key); 
void view(Tree* t, int level);    
void delAll(Tree* t);             
int task(Tree* tree);    // Подсчёт правых

int c = 0;      
Tree* Root = NULL;     //указатель корня
int countRightLeaves(Tree* tree) {
    if (tree == NULL) {
        return 0;
    }

    int rightLeaves = 0;

    // Если текущий узел является листом и он правый, увеличиваем счетчик на 1
    if (tree->Left == NULL && tree->Right == NULL && tree->isRightChild) {
        rightLeaves += 1; // Если это правый лист без дочерних элементов, увеличиваем счетчик
    }

    // Рекурсивно обходим оба поддерева и считаем количество правых листьев в них
    rightLeaves += countRightLeaves(tree->Left); // Обходим левое поддерево
    rightLeaves += countRightLeaves(tree->Right); // Обходим правое поддерево

    // Возвращаем общее количество правых листьев
    return rightLeaves;
}

int main() {
    setlocale(0, "Russian");
    int key, choice, numLeft = 0;
    Tree* rc;
    char s[5], letter;

    for (;;) {
        cout << "1 - создание дерева\n";
        cout << "2 - добавление элемента\n";
        cout << "3 - поиск по ключу\n";
        cout << "4 - удаление элемента\n";
        cout << "5 - вывод дерева\n";
        cout << "6 - очистка дерева\n";
        cout << "7 - количество правых дочерних вершин\n";
        cout << "8 - выход\n";
        cout << "ваш выбор?\n";

        // Проверка на ввод буквы
        if (!(cin >> choice)) {
            cout << "Ошибка: введена буква. Пожалуйста, введите число.\n";
            cin.clear(); // Очистка флагов ошибок ввода
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Очистка буфера ввода
            continue; // Пропускаем текущую итерацию цикла
        }

        cout << "\n";
        switch (choice) {
        case 1:  Root = makeTree(Root); break;
        case 2:  cout << "\nВведите ключ: "; cin >> key;
            cout << "Введите слово: "; cin >> s;
            insertElem(Root, key, s); break;
        case 3:
            cout << "\nВведите ключ: ";
            // Проверка на корректный ввод ключа (целое число)
            while (!(cin >> key)) {
                cout << "Ошибка: введите целое число для ключа: ";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
            cout << "Найденное слово= ";
            if (search(Root, key) != NULL) {
                cout << search(Root, key)->text;
            }
            else {
                cout << "Элемент с таким ключом не найден";
            }
            cout << endl;
            break;

        case 4:
            cout << "\nВведите удаляемый ключ: ";
            // Проверка на корректный ввод ключа (целое число)
            while (!(cin >> key)) {
                cout << "Ошибка: введите целое число для ключа: ";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
            Root = delet(Root, key);
            break;

        case 5:  if (Root->key >= 0) {
            cout << "Дерево повернуто на 90 град. влево" << endl;
            view(Root, 0);
        }
              else cout << "Дерево пустое\n"; break;
        case 6:  delAll(Root); break;
        case 7:  numLeft = task(Root);
            cout << "Количество правых листьев = " << numLeft - 1 << endl;
            break;
        case 8:  exit(0);
        }
    }
}

Tree* makeTree(Tree* Root)    //Создание дерева
{
    int key;
    char s[20];    // для ключа и строки

    cout << "Конец ввода - отрицательное число\n\n";

    // Проверка на корректный ввод ключа корня (неотрицательное число)
    do {
        cout << "Введите ключ корня (неотрицательное число): ";
        while (!(cin >> key)) {
            cout << "Ошибка: введите целое число для ключа корня: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        if (key < 0) {
            cout << "Ошибка: ключ корня должен быть неотрицательным.\n";
        }
    } while (key < 0);

    // Проверка на корректный ввод слова корня (не более 4 букв)
    cout << "Введите слово корня (не более 4 букв): ";
    cin >> s;
    while (strlen(s) > 4 || strlen(s) == 0) {
        cout << "Ошибка: введите слово длиной до 4 букв: ";
        cin >> s;
    }

    Root = list(key, s);    // установка указателя на корень

    while (1)                //добавление элементов
    {
        // Проверка на корректный ввод ключа элемента
        cout << "\nВведите ключ: ";
        while (!(cin >> key)) {
            cout << "Ошибка: введите целое число для ключа элемента: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        if (key < 0) break;       //признак выхода (ключ < 0)   

        // Проверка на корректный ввод слова элемента (не более 4 букв)
        cout << "Введите слово (не более 4 букв): ";
        cin >> s;
        while (strlen(s) > 4 || strlen(s) == 0) {
            cout << "Ошибка: введите слово длиной до 4 букв: ";
            cin >> s;
        }

        insertElem(Root, key, s);
    }

    return Root;
}



Tree* list(int i, char* s)     //Создание нового элемента
{
    Tree* t = new Tree[sizeof(Tree)];        // выделение памяти
    t->key = i;            // ключ
    for (i = 0; i < 5; i++)
        *((t->text) + i) = *(s + i);        // создание
    t->Left = t->Right = NULL;            // правая и левая ветви
    return t;
}

Tree* insertElem(Tree* t, int key, char* s) {
    Tree* Prev = NULL;
    int find = 0;

    // Поиск места для вставки нового элемента
    while (t && !find) {
        Prev = t;
        if (key == t->key)
            find = 1;
        else if (key < t->key)
            t = t->Left;
        else
            t = t->Right;
    }

    if (!find) {
        // Создание нового узла
        Tree* newNode = list(key, s);

        // Вставка нового элемента
        if (!Prev) // Если дерево пустое
            t = newNode;
        else if (key < Prev->key)
            Prev->Left = newNode;
        else
            Prev->Right = newNode;

        return newNode; // Возвращаем указатель на новый элемент
    }
    else {
        cout << "Элемент с ключом " << key << " уже существует." << endl;
        return NULL;
    }
}

Tree* delet(Tree* Root, int key)  //Удаление элемента по ключу
{    // Del, Prev_Del - удаляемый элемент и его предыдущий ;
    // R, Prev_R - элемент, на который заменяется удаленный, и его родитель; 
    Tree* Del, * Prev_Del, * R, * Prev_R;
    Del = Root;
    Prev_Del = NULL;
    while (Del != NULL && Del->key != key)   //поиск элемента и его родителя 
    {
        Prev_Del = Del;
        if (Del->key > key)
            Del = Del->Left;
        else
            Del = Del->Right;
    }
    if (Del == NULL)              // элемент не найден
    {
        puts("\nНет такого ключа");
        return Root;
    }
    if (Del->Right == NULL) // поиск элемента R для замены
        R = Del->Left;        // переход на левую ветвь
    else
        if (Del->Left == NULL)
            R = Del->Right;        // или на правую
        else
        {
            Prev_R = Del; //поиск самого правого элемента в левом поддереве
            R = Del->Left;
            while (R->Right != NULL)
            {
                Prev_R = R;
                R = R->Right;
            }
            if (Prev_R == Del) // найден элемент для замены R и его родителя Prev_R 
                R->Right = Del->Right;
            else
            {
                R->Right = Del->Right;
                Prev_R->Right = R->Left;
                R->Left = Prev_R;
            }
        }
    if (Del == Root) Root = R;    //удаление корня и замена его на R
    else
        // поддерево R присоединяется к родителю удаляемого узла
        if (Del->key < Prev_Del->key)
            Prev_Del->Left = R; // на левую ветвь 
        else
            Prev_Del->Right = R;    // на правую ветвь
    int tmp = Del->key;
    cout << "\nУдален элемент с ключом " << tmp << endl;
    delete Del;
    return Root;
}

Tree* search(Tree* n, int key)  //Поиск элемента по ключу 
{
    Tree* rc = n;
    if (rc != NULL) {
        if (key < (key, n->key))
            rc = search(n->Left, key);
        else
            if (key > (key, n->key))
                rc = search(n->Right, key);
    }
    else
        cout << "Нет такого элемента\n";
    return rc;
}

void view(Tree* t, int level) {
    if (t) {
        // Рекурсивный вызов для правого поддерева с увеличением уровня
        view(t->Right, level + 1);

        // Вывод отступов для текущего уровня
        for (int i = 0; i < level; i++)
            cout << "   ";

        // Вывод уровня и содержимого текущего узла
        cout << "Уровень " << level << ": " << t->key << ' ' << t->text << endl;

        // Рекурсивный вызов для левого поддерева с увеличением уровня
        view(t->Left, level + 1);
    }
}


void delAll(Tree* t) //Очистка дерева
{
    if (t != NULL) {
        delAll(t->Left);
        delAll(t->Right);
        delete t;
    }
}

int task(Tree* tree) {
    return countRightLeaves(tree);
}

