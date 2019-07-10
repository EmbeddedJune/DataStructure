#pragma once
#include <iostream>

class Polynomial
{
private:
	int m_degree;
	float* m_coef = nullptr;

public:
	Polynomial(const int& deg = 0);

	void negate();
	void add(Polynomial& p2);
	void read();
	void display();

	~Polynomial()
	{
		delete[] m_coef;
	}
};