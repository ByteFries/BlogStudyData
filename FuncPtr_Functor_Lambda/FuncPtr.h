#pragma once
#include "framework.h"

void Func1();

void Func2();

int Quick(vector<int>& v, int left, int right, bool(*compare)(int num1, int num2));
using compareFunc = bool(*)(int, int);

void QuickSort(vector<int>& v, int left, int right, compareFunc compare); //using���� ���� ���� ���� ����

bool Ascending(int num1, int num2);
bool Descending(int num1, int num2);

class TestClass
{
public:
	TestClass(string name) :name(name) {}

	void MemberFunc()
	{
		cout << name << "�� �ɹ� �Լ� ȣ��" << endl;
	}

	static void StaticMemberFunc()
	{
		cout << "���� ��� �Լ� ȣ��" << endl;
	}

private:
	string name;
};

template<typename T>
void Print(T value)
{
	cout << value << endl;
}

void FuncPtr();