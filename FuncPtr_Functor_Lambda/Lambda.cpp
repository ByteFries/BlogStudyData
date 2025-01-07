#include "Lambda.h"

void Lambda()
{

	[]()->void {cout << "클로져 객체(임시 객체) 생성하여 함수 객체처럼 동작" << endl;}();
	[] {cout << "인자나 리턴 값은 생략도 가능";}; //인자가 없을 때와 리턴 값이 void 일 때만


	int num = 0;
	[&num]()->void { cout << "외부 데이터 접근가능: " << num << endl; }(); //참조로 가져옴


	//[num]() {num = 1;}; 값으로 가져올 때는 const 형태로 가져오기에 값 수정 불가능
	[num]() mutable {num = 1;}; //mutable을 붙이면 내부에서만 수정 가능, 외부는 변하지 않는다.

	LambdaCounter counter; //하지만 클래스 매개변수의 경우 [=] 로 캡쳐할 시 객체의 this도 캡쳐하여, 맴버 변수에 접근이 가능하고, 수정할 수 도 있다.
	cout << counter.count << endl;
	counter.AddOne();
	cout << counter.count << endl;

	int total = 0;
	vector<int> v;
	
	TemplateFill(v, [&v]()->bool {return v.size() < 10;}); //클로져 객체도 타입이니 템플릿에서 사용이 가능하다.

	for_each(v.begin(), v.end(), [&total](int num) {total += num;}); //std 에서도 사용 가능함.

	cout << "벡터 안 요소들의 합: " << total << endl;

	auto autoLambda = [] {cout << "auto로 저장한 람다" << endl;};	//auto로 람다 저장 가능
	void(*funcPtrLamda)() = [] {cout << "함수 포인터로 저장한 람다" << endl;}; //캡쳐한 데이터가 없으면 함수 포인터도 사용 가능
	autoLambda();
	funcPtrLamda();

	int tmp = 0;
	auto captureTime = [tmp] {cout << "tmp: " << tmp << endl;}; //값으로 캡쳐하면, 클로져 객체가 생성될 때 기준의 값을 저장
	tmp = 10;
	captureTime();


}