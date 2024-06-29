#pragma once
#include<iostream>
#include<fstream>
#include<string>
#include"Windows.h"
struct node {
	int data;
	node* next;
};
struct stack
{
	node* tail;
};
using namespace std;
void clear(stack*& tail);
void WriteToFile(stack* tail);
void ReadFromFile(stack* tail);
void pop(stack*& tail);
void push(int x, stack*& tail);
void PrintStack(stack* tail);
void DivideStack(stack*& tail);