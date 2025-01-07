#pragma once
#include "framework.h"

struct TestFunctor
{
	void operator()()
	{
		cout << "Functor 호출" << endl;
	}

	void operator()(int num)
	{
		cout << "매개변수: " << num << endl;
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
		cout << "매개변수의 타입: " << typeid(value).name() << " ";
		cout << "매개변수 값: " << value << endl;
	}
};

void Functor();