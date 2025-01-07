#include "Functor.h"
#include <typeinfo>

void Functor()
{
	/*---------------------------------------- ������� ----------------------------------------*/
	TestFunctor functor; //��ü�� �����ϰ� () ���۷����͸� �����ε��ϴ� ���
	functor();

	/*---------------------------------------- Ư¡ ----------------------------------------*/
	Counter countFunctor; //Ŭ������ ��������⿡, ��� ������ ���� ���¸� ������ �� �ִ�
	countFunctor();
	countFunctor();
	countFunctor();
	countFunctor();
	countFunctor();

	vector<pair<int, string>> v; //STL���� Functor�� ���� ����ϱ⿡ ȣȯ���� ����.
	v.push_back({2, "string2"});
	v.push_back({1, "string1"});

	sort(v.begin(), v.end(), Compare()); //����� ���� �ڷ����� ������ �� Functor ��� ����

	for (int i = 0; i < v.size(); i++)
	{
		cout << v[i].first << " " << v[i].second << endl;
	}

	TemplateFunctor templateFunctor; //���� template�� ����
	templateFunctor(5);
	templateFunctor(5.0);
}