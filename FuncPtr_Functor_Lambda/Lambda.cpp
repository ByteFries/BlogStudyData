#include "Lambda.h"

void Lambda()
{

	[]()->void {cout << "Ŭ���� ��ü(�ӽ� ��ü) �����Ͽ� �Լ� ��üó�� ����" << endl;}();
	[] {cout << "���ڳ� ���� ���� ������ ����";}; //���ڰ� ���� ���� ���� ���� void �� ����


	int num = 0;
	[&num]()->void { cout << "�ܺ� ������ ���ٰ���: " << num << endl; }(); //������ ������


	//[num]() {num = 1;}; ������ ������ ���� const ���·� �������⿡ �� ���� �Ұ���
	[num]() mutable {num = 1;}; //mutable�� ���̸� ���ο����� ���� ����, �ܺδ� ������ �ʴ´�.

	LambdaCounter counter; //������ Ŭ���� �Ű������� ��� [=] �� ĸ���� �� ��ü�� this�� ĸ���Ͽ�, �ɹ� ������ ������ �����ϰ�, ������ �� �� �ִ�.
	cout << counter.count << endl;
	counter.AddOne();
	cout << counter.count << endl;

	int total = 0;
	vector<int> v;
	
	TemplateFill(v, [&v]()->bool {return v.size() < 10;}); //Ŭ���� ��ü�� Ÿ���̴� ���ø����� ����� �����ϴ�.

	for_each(v.begin(), v.end(), [&total](int num) {total += num;}); //std ������ ��� ������.

	cout << "���� �� ��ҵ��� ��: " << total << endl;

	auto autoLambda = [] {cout << "auto�� ������ ����" << endl;};	//auto�� ���� ���� ����
	void(*funcPtrLamda)() = [] {cout << "�Լ� �����ͷ� ������ ����" << endl;}; //ĸ���� �����Ͱ� ������ �Լ� �����͵� ��� ����
	autoLambda();
	funcPtrLamda();

	int tmp = 0;
	auto captureTime = [tmp] {cout << "tmp: " << tmp << endl;}; //������ ĸ���ϸ�, Ŭ���� ��ü�� ������ �� ������ ���� ����
	tmp = 10;
	captureTime();


}