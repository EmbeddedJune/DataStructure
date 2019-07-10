#include "polynomial.h"

Polynomial::Polynomial(const int& degree)
{
	this->m_degree = degree;
}

void Polynomial::negate()
{
	for (unsigned i = 0; i < this->m_degree; ++i)
		this->m_coef[i] *= (-1);
}

void Polynomial::add(Polynomial& p2)
{
	if (this->m_degree > p2.m_degree)
	{
		for (unsigned i = 0; i < p2.m_degree; ++i)
			this->m_coef[this->m_degree -1-i] += p2.m_coef[p2.m_degree - 1 - i];
	}
	else
	{
		for (unsigned i = 0; i < this->m_degree; ++i)
			this->m_coef[this->m_degree - 1 - i] += p2.m_coef[p2.m_degree - 1 - i];
	}
}

void Polynomial::read()
{
	std::cout << "Input size >> ";
	int inputNum(0);
	std::cin >> inputNum;

	this->m_degree = inputNum;
	this->m_coef = new float[inputNum];

	std::cout << "Input Coefs >> ";
	for (unsigned i = 0; i < inputNum; ++i)
	{
		std::cin >> this->m_coef[i];
	}
}

void Polynomial::display()
{
	for (unsigned i = 0; i < m_degree; ++i)
	{
		std::cout << this->m_coef[i] << "x^" << m_degree - i - 1 <<" +\t";
	}
	std::cout << "\n\n";
}

int main()
{
	Polynomial poly1;
	Polynomial poly2;

	poly1.read();
	poly2.read();

	poly1.add(poly2);

	poly1.display();

	poly1.negate();

	poly1.display();
}