#include "studentstack.h"
#include <string>

StudentStack::StudentStack()
{
	top = -1;
	data = new Student [MAX_SIZE];
}

bool StudentStack::isEmpty() { return (top == -1); }
bool StudentStack::isFull() { return (top == MAX_SIZE - 1); }
void StudentStack::push(Student input)
{
	if(isFull())
		std::cerr << "Stack is empty, there is no data to show\n";
	else
		data[++top] = input;
}
void StudentStack::pop()
{
	if (isEmpty())
	{
		std::cerr << "Stack is empty, there is no data to show\n";
	}
	else
		top--;
}
Student StudentStack::peek()
{
	if (isEmpty())
	{
		std::cerr << "Stack is empty, there is no data to show\n";
	}
	else
		return data[top];
}
void StudentStack::display()
{
	for (int i = 0; i <= top; ++i)
	{
		data[i].display();
		std::cout << "\n";
	}
}

int main()
{
	std::cout << "�л� ���� ���α׷�\n";	
	StudentStack stack;
	std::string inputName;
	std::string inputDept;
	int input, inputID;

	do
	{
		std::cout << "�ɼ��� �Է��ϼ���\n" << "1) ����\t2) ����/��ȯ\t3) ������\t4) ���\t5) -1�Է½� ����\n";
		std::cin >> input;
		if (input == 1)
		{
			std::cout << "�л� ������ �Է��ϼ��� >> ";
			std::cin >> inputName >> inputID >> inputDept;
			stack.push(Student(inputName, inputID, inputDept));
		}
		else if (input == 2)
			stack.pop();
		else if (input == 3)
			stack.peek().display();
		else if (input == 4)
			stack.display();
		std::cin.clear();
	} while (input != -1);
}
