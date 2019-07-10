#pragma once

#include <iostream>

const int MAX_SIZE = 10;

class ArrayStack
{
private:
	int top;
	int* data;

public:
	ArrayStack();

	bool isEmpty();
	bool isFull();
	void push(const int &input);
	int pop();
	int peek();
	void display();
};