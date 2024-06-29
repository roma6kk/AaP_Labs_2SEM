#define _CRT_SECURE_NO_WARNINGS // ������ �� ������ ���������� ��������� � �������������� ������������ �������

#include <iostream>
#include <chrono>
#include "HashTable.h"

using namespace std;

int main() {
    setlocale(LC_ALL, "Rus"); // ��������� ������ ��� ������ ������� ��������
    // ������� ���-������� ��������� 10, 100 � 1000
    HashTable hashTable10(10);
    HashTable hashTable100(100);
    HashTable hashTable1000(1000);

    // ��������� ��������� �������� � ���-�������
    srand(time(NULL));
    for (int i = 0; i < 1000; i++) {
        char name[50];
        int year = rand() % 10000;
        sprintf(name, "����� %d", i);
        hashTable10.insertItem(name, year);
        hashTable100.insertItem(name, year);
        hashTable1000.insertItem(name, year);
    }

    // �������� ����� ������ �������� � ������ ���-�������
    int searchYear = rand() % 10000;
    cout << "���� ������� � ����� ������� " << searchYear << endl;

    auto start10 = chrono::high_resolution_clock::now();
    hashTable10.searchItem(searchYear);
    auto end10 = chrono::high_resolution_clock::now();
    cout << "����� ������ � ���-������� �������� 10: "
        << chrono::duration_cast<chrono::microseconds>(end10 - start10).count() << " �����������" << endl;

    auto start100 = chrono::high_resolution_clock::now();
    hashTable100.searchItem(searchYear);
    auto end100 = chrono::high_resolution_clock::now();
    cout << "����� ������ � ���-������� �������� 100: "
        << chrono::duration_cast<chrono::microseconds>(end100 - start100).count() << " �����������" << endl;

    auto start1000 = chrono::high_resolution_clock::now();
    hashTable1000.searchItem(searchYear);
    auto end1000 = chrono::high_resolution_clock::now();
    cout << "����� ������ � ���-������� �������� 1000: "
        << chrono::duration_cast<chrono::microseconds>(end1000 - start1000).count() << " �����������" << endl;

    return 0;
}
