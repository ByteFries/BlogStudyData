#pragma once
#include "framework.h"

struct TestFunctor
{
	void operator()()
	{
		cout << "Functor ȣ��" << endl;
	}

	void operator()(int num)
	{
		cout << "�Ű�����: " << num << endl;
	}
};

class Counter
{
public:
	void operator()()
	{
		cout << "Count: " << ++counter << endl;
	}

private:
	int counter = 0;
};

struct Compare
{
	bool operator() (pair<int, string> p1, pair<int, string> p2)
	{
		return p1.first < p2.first;
	}
};

class TemplateFunctor
{
public:
	template<typename T>
	void operator()(T value)
	{
		cout << "�Ű������� Ÿ��: " << typeid(value).name() << " ";
		cout << "�Ű����� ��: " << value << endl;
	}
};

void Functor();