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

void QuickSort(vector<int>& v, int left, int right, compareFunc compare) //using으로 보기 좋게 변경 가능
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
	/*---------------------------------------- 생성방법 ----------------------------------------*/

	void(*funcPtr)(/*매개변수 타입*/) = Func1; //함수 포인터 생성
	(*funcPtr)();							   //함수 포인터로 함수 호출.
	funcPtr = Func2;						   //C++에선 함수를 암묵적으로 함수 주소로 변환해줌
	funcPtr();								   //C++에선 함수의 암묵적 역참조를 허용

	/*--------------------------------------- 매개변수 ----------------------------------------*/

	vector<int> v = { 1,5,2,8,9,43,7,3 };

	QuickSort(v, 0, v.size() - 1, Ascending); //함수 포인터를 매개 변수로 이용 가능하다.

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

	/*--------------------------------------- 맴버함수 ----------------------------------------*/

	TestClass test1("테스트1"), test2("테스트2");
	void (TestClass:: * memberFuncPtr)() = &TestClass::MemberFunc; //맴버함수의 선언, TestClass:: 이 TestClass 클래스의 멤버 함수를 가리킨다는 것을 명시

	(test1.*memberFuncPtr)();
	(test2.*memberFuncPtr)(); //멤버함수 포인터는 객체가 필요하다.

	void (*staticMemberFuncPtr)() = &TestClass::StaticMemberFunc; //정적 멤버함수는 객체와 독립적이기에 일반 함수 포인터처럼 생성
	staticMemberFuncPtr();

	/*--------------------------------------- 템플릿 함수 ----------------------------------------*/

	void(*templateFuncPtrInt)(int) = Print<int>; // int 타입에 대한 템플릿 함수 포인터
	void(*templateFuncPtrStr)(string) = Print<string>; // string 타입에 대한 템플릿 함수 포인터
	templateFuncPtrInt(10);
	templateFuncPtrStr("스트링");			//함수 포인터를 사용할 경우, 템플릿 파라미터 자동 유추가 불가능하니, 구체적인 타입을 명시해야한다.

	/*--------------------------------------- 함수 포인터 배열 ----------------------------------------*/

	void(*funcArr[])() = { Func1, Func2 };

	funcArr[0]();
	funcArr[1]();

}
