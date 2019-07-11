#pragma once

#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

#define MAX_STACK_SIZE  20

class OperandStack
{
private:
	double* data = new double [MAX_STACK_SIZE];
	int top = -1;

public:
	OperandStack() {};
	bool isEmpty();
	bool isFull();
	void push(const double& data);
	double pop();
	~OperandStack() { delete[] data; }
};