#pragma once
#include <iostream>
#include <string>
#include <cstring>
#include <cstdlib>
#include <cstdio>

#define MAX_SIZE 100

class Student
{
private:
	std::string m_name;
	int m_id;
	std::string m_dept;

public:
	Student(std::string name = "default", const int& id = 0 , std::string dept = "default")
	{
		m_name = name;
		m_id = id;
		m_dept = dept;
	}
	void display() { std::cout << "이름: " << m_name << "\t학번: " << m_id << "\t학과: " << m_dept; }
};