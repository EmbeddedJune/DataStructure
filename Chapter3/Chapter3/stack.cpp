#include "stack.h"

ArrayStack::ArrayStack()
{
	top = -1;
	data = new int[MAX_SIZE];
}
bool ArrayStack::isEmpty() { return (top == -1); }
bool ArrayStack::isFull() { return (top == MAX_SIZE - 1); }
void ArrayStack::push(const int& input)
{
	if (isFull())
		std::cerr << "Stack is already full!\n";
	else
		data[++top] = input;
}
int ArrayStack::pop()
{
	if (isEmpty())
	{
		std::cerr << "Stack is already empty!\n";
		return 0;
	}
	else
		return data[top--];
}
int ArrayStack::peek()
{
	if (isEmpty())
	{
		std::cerr << "Stack is empty, there is no data to show\n";
		return 0;
	}
	else
		return data[top];
}
void ArrayStack::display()
{
	if (isEmpty())
		std::cerr << "Stack is empty, there is no data to show\n";

	else
	{
		for (int i = 0; i <= top; ++i)
			std::cout << data[i] << " ";
		std::cout << "\n\n";
	}
}

int main()
{
	int input, num;
	ArrayStack stack;

	do
	{
		std::cout << "옵션을 입력하세요\n" << "1) 삽입\t2) 삭제/반환\t3) 엿보기\t4) 출력\t5) -1입력시 종료\n";
		std::cin >> input;
		if (input == 1)
		{
			std::cout << "숫자를 입력하세요 >> ";
			std::cin >> num;
			stack.push(num);
		}
		else if (input == 2)
			std::cout << stack.pop() << "\n\n";
		else if (input == 3)
			std::cout << stack.peek() << "\n\n";
		else if (input == 4)
			stack.display();
		std::cin.clear(); 
	} while (input != -1);
}