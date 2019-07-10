#pragma once
#include <iostream>

struct contents
{
	float data;
	int coef;
};
class SparsePolynomial
{
private:
	int m_degree;
	contents* m_coef = nullptr;

public:
	SparsePolynomial(const int& deg = 0);

	void negate();
	void add(SparsePolynomial& p2);
	void read();
	void display();

	~SparsePolynomial()
	{
		delete[] m_coef;
	}
};
