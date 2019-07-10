#include "sparse_polynomial.h"

SparsePolynomial::SparsePolynomial(const int& degree)
{
	this->m_degree = degree;
	m_coef->coef = 0;
	m_coef->data = 0.0;
}

void SparsePolynomial::negate()
{
	for (unsigned i = 0; i < this->m_degree; ++i)
		m_coef[i].data *= (-1);
}

void SparsePolynomial::add(SparsePolynomial& p2)
{
	
}

void SparsePolynomial::read()
{
	std::cout << "Input size >> ";
	int inputNum(0);
	std::cin >> inputNum;

	this->m_degree = inputNum;
	this->m_coef = new contents[inputNum];

	std::cout << "Input Coefs >> ";
	for (unsigned i = 0; i < inputNum; ++i)
	{
		std::cin >> this->m_coef[i].data;
	}
}

void SparsePolynomial::display()
{
	for (unsigned i = 0; i < m_degree; ++i)
	{
		std::cout << this->m_coef[i].data << "x^" << this->m_coef[i].coef << " +\t";
	}
	std::cout << "\n\n";
}

int main()
{
	SparsePolynomial poly1;
	SparsePolynomial poly2;

	poly1.read();
	poly2.read();

	poly1.add(poly2);
	poly1.display();

	poly1.negate();
	poly1.display();
}