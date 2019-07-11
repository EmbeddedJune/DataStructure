#pragma once
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstdio>	

using namespace std;

const int MAX_SIZE = 10;

class ArrayStack
{
private:
	int top;
	char* data;

public:
	ArrayStack()
	{
		top = -1;
		data = new char[MAX_SIZE];
	}

	bool isEmpty() { return top == -1; }
	bool isFull() { return top == MAX_SIZE - 1; }
	void push(const char& input)
	{
		if (isFull()) cerr << "Error, stack is full\n";
		else data[++top] = input;
	}
	char pop()
	{
		if (isEmpty()) cerr << "Error, stack is empty\n";
		else return data[top--];
	}
	char peek()
	{
		if (isEmpty()) cerr << "Error, stack is empty\n";
		else return data[top];
	}
	~ArrayStack() { delete[] data; }
};
