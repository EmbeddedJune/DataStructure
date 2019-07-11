#include "OperandStack.h"

bool OperandStack::isEmpty() { return (top == -1); }
bool OperandStack::isFull() { return (top == MAX_STACK_SIZE - 1); }

void OperandStack::push(const double& input)
{
	if (isFull())
		cerr << "Error, stack is full\n";
	else
		data[++top] = input;
}

double OperandStack::pop()
{
	if (isEmpty())
	{
		cerr << "Error, stack is empty\n";
		return NULL;
	}
	else
		return data[top--];
}

double calcPostfixExpr(FILE *fp = stdin)
{
	char c;
	OperandStack stack;

	while ((c = getc(fp) != '\n'))
	{
		if (c == '+' || c == '-' || c == '*' || c == '/')
		{
			double val2 = stack.pop();
			double val1 = stack.pop();
			switch (c)
			{
			case '+': stack.push(val1 + val2); break;
			case '-': stack.push(val1 - val2); break;
			case '*': stack.push(val1 * val2); break;
			case '/': stack.push(val1 / val2); break;
			}
		}
		else if (c >= '0' && c <= '9')
		{
			ungetc(c, fp);
			double val3;
			fscanf_s(fp, "%lf", &val3);
			stack.push(val3);
		}
	}
	return (stack.pop());
}

int main()
{
	cout << "수식을 입력하세요(Postfix) = ";
	
	double result = calcPostfixExpr();
	cout << "계산 결과 = " << result << '\n';
}