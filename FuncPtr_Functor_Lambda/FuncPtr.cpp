#include "FuncPtr.h"

#include <utility>


void Func1()
{
	cout << "Func1" << endl;
}

void Func2()
{
	cout << "Func2" << endl;
}

int Quick(vector<int>& v, int left, int right, bool(*compare)(int num1, int num2))
{
	int pivot = v[right];
	int leftIndex = left;

	for (int i = left; i < right; i++)
	{
		if (compare(v[i], pivot))
		{
			swap(v[i], v[leftIndex++]);
		}
	}

	swap(v[leftIndex], v[right]);

	return leftIndex;
}

using compareFunc = bool(*)(int, int);

void QuickSort(vector<int>& v, int left, int right, compareFunc compare) //using���� ���� ���� ���� ����
{
	if (left < right)
	{
		int pivot = Quick(v, left, right, compare);

		QuickSort(v, left, pivot - 1, compare);
		QuickSort(v, pivot + 1, right, compare);
	}
}

bool Ascending(int num1, int num2)
{
	return num1 < num2;
}

bool Descending(int num1, int num2)
{
	return num2 < num1;
}


void FuncPtr()
{
	/*---------------------------------------- ������� ----------------------------------------*/

	void(*funcPtr)(/*�Ű����� Ÿ��*/) = Func1; //�Լ� ������ ����
	(*funcPtr)();							   //�Լ� �����ͷ� �Լ� ȣ��.
	funcPtr = Func2;						   //C++���� �Լ��� �Ϲ������� �Լ� �ּҷ� ��ȯ����
	funcPtr();								   //C++���� �Լ��� �Ϲ��� �������� ���

	/*--------------------------------------- �Ű����� ----------------------------------------*/

	vector<int> v = { 1,5,2,8,9,43,7,3 };

	QuickSort(v, 0, v.size() - 1, Ascending); //�Լ� �����͸� �Ű� ������ �̿� �����ϴ�.

	for (int i = 0; i < v.size(); i++)
	{
		cout << v[i] << " ";
	}
	cout << endl;
	QuickSort(v, 0, v.size() - 1, Descending);

	for (int i = 0; i < v.size(); i++)
	{
		cout << v[i] << " ";
	}
	cout << endl;

	/*--------------------------------------- �ɹ��Լ� ----------------------------------------*/

	TestClass test1("�׽�Ʈ1"), test2("�׽�Ʈ2");
	void (TestClass:: * memberFuncPtr)() = &TestClass::MemberFunc; //�ɹ��Լ��� ����, TestClass:: �� TestClass Ŭ������ ��� �Լ��� ����Ų�ٴ� ���� ���

	(test1.*memberFuncPtr)();
	(test2.*memberFuncPtr)(); //����Լ� �����ʹ� ��ü�� �ʿ��ϴ�.

	void (*staticMemberFuncPtr)() = &TestClass::StaticMemberFunc; //���� ����Լ��� ��ü�� �������̱⿡ �Ϲ� �Լ� ������ó�� ����
	staticMemberFuncPtr();

	/*--------------------------------------- ���ø� �Լ� ----------------------------------------*/

	void(*templateFuncPtrInt)(int) = Print<int>; // int Ÿ�Կ� ���� ���ø� �Լ� ������
	void(*templateFuncPtrStr)(string) = Print<string>; // string Ÿ�Կ� ���� ���ø� �Լ� ������
	templateFuncPtrInt(10);
	templateFuncPtrStr("��Ʈ��");			//�Լ� �����͸� ����� ���, ���ø� �Ķ���� �ڵ� ���߰� �Ұ����ϴ�, ��ü���� Ÿ���� ����ؾ��Ѵ�.

	/*--------------------------------------- �Լ� ������ �迭 ----------------------------------------*/

	void(*funcArr[])() = { Func1, Func2 };

	funcArr[0]();
	funcArr[1]();

}
