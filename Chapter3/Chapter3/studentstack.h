#pragma once
#include "student.h"

class StudentStack
{
private:
	int top;
	Student* data;

public:
	StudentStack();

	bool isEmpty();
	bool isFull();
	void push(Student input);
	void pop();
	Student peek();
	void display();
};