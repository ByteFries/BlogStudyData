#include "Functor.h"
#include <typeinfo>

void Functor()
{
	/*---------------------------------------- 생성방법 ----------------------------------------*/
	TestFunctor functor; //객체를 생성하고 () 오퍼레이터를 오버로드하는 방식
	functor();

	/*---------------------------------------- 특징 ----------------------------------------*/
	Counter countFunctor; //클래스로 만들어지기에, 멤버 변수를 통해 상태를 저장할 수 있다
	countFunctor();
	countFunctor();
	countFunctor();
	countFunctor();
	countFunctor();

	vector<pair<int, string>> v; //STL에서 Functor를 자주 사용하기에 호환성이 좋다.
	v.push_back({2, "string2"});
	v.push_back({1, "string1"});

	sort(v.begin(), v.end(), Compare()); //사용자 정의 자료형을 정렬할 때 Functor 사용 가능

	for (int i = 0; i < v.size(); i++)
	{
		cout << v[i].first << " " << v[i].second << endl;
	}

	TemplateFunctor templateFunctor; //물론 template도 가능
	templateFunctor(5);
	templateFunctor(5.0);
}