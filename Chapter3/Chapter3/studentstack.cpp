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
	std::cout << "학생 스택 프로그램\n";	
	StudentStack stack;
	std::string inputName;
	std::string inputDept;
	int input, inputID;

	do
	{
		std::cout << "옵션을 입력하세요\n" << "1) 삽입\t2) 삭제/반환\t3) 엿보기\t4) 출력\t5) -1입력시 종료\n";
		std::cin >> input;
		if (input == 1)
		{
			std::cout << "학생 정보를 입력하세요 >> ";
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
