#include "EvalPostfixMain.h"

inline int precedence(char op)
{
	switch (op)
	{
	case '(': case ')': return 0;
	case '+': case '-': return 1;
	case '*': case '/': return 2;
	}
	return -1;
}

void infixToPostfix(FILE* fp = stdin)
{
	char c, op;
	double val;
	ArrayStack stack;

	while ((c = getc(fp)) != '\n')
	{
		if (c >= '0' && c <= '9')
		{
			ungetc(c, fp);
			fscanf(fp, "%lf", &val);
			printf("%4.1f", val);
		}
		else if (c == '(') stack.push(c);
		else if (c == ')')
		{
			while (!stack.isEmpty())
			{
				op = stack.pop();
				if (op == '(')
					break;
				else
					printf("%c", op);
			}
		}
		else if (c == '+' || c == '-' || c == '*' || c == '/')
		{
			while (!stack.isEmpty())
			{
				op = stack.peek();
				if (precedence(c) <= precedence(op))
				{
					printf("%c", op);
					stack.pop();
				}
				else
					break;
			}
			stack.push(c);
		}
	}
	while (!stack.isEmpty())
		printf("%c", stack.pop());
	cout << '\n';
}
int main()
{
	cout << "수식을 입력하세요 >> ";
	infixToPostfix();
	return 0;
}