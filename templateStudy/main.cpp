#include <iostream>
#include <vector>

using namespace std;

template<typename T> //기본적인 템플릿 선언
class Test
{
public:
	Test<T>();
	~Test<T>();

private:
};

template<> //템플릿의 특수화
class Test<int>
{
public:
	Test<int>();
	~Test<int>();
private:
};

template<typename T, int a> //매개변수 대신 사용 가능하다
void TemplateFunc(T type)
{
	cout << type + a << endl;
}

template<typename A> //반드시 재귀 종료 함수가 필요하다.
void Print(A a)
{
	cout << a << endl;
}

template<typename A, typename... B> //가변 길이 템플릿 함수
void Print(A a, B... b)
{
	cout << a << " ";
	Print(b...);
}

template<typename T, typename... Args> //가변 길이 인자를 이용한 벡터 생성 함수
vector<T> GetVector(Args... args)
{
	return vector<T>{args...};
}

template<typename T, typename... Args> //종료 함수 없이 가변 길이 인자 템플릿 재귀
T Sum(Args... args)
{
	return (... + args); //17 이상부터 fold 기능이 추가
}

template<int num> //인자를 타입이 아닌 값으로 사용하기
struct Int
{
	static const int value = num;
};

template<typename T, typename U> //값으로 받아 연산도 가능하다
struct SumInt
{
	static const int value = T::value + U::value;
};

int Factorial(const int n) //팩토리얼 재귀 함수
{
	return n == 0 ? 1 : n * Factorial(n - 1);
}


template<int Num> //템플릿을 이용한 팩토리얼 함수
struct FactorialS
{
	static const int value = Num * FactorialS<Num-1>::value;
};

template<> //종료 함수
struct FactorialS<1>
{
	static const int value = 1;
};

int GCD(int a, int b) //최대 공약수
{
	if (b == 0) return a;
	return GCD(b, a % b);
}

template<int num1, int num2>
struct GCDTemplate
{
	static const int value = GCDTemplate<num2, num1 % num2>::value; 	
};

template<int num1>
struct GCDTemplate<num1, 0>
{
	static const int value = num1;
};

bool IsPrime(int target, int denom = 2)
{
	if (denom * denom > target) return true;
	if (target % denom == 0) return false;
	return IsPrime(target, denom + 1);
}

template<int num1, int num2 = num1 - 1>
struct IsPrimeTemplate
{
	static const bool value = (num1 % num2 == 0) ? false : IsPrimeTemplate<num1, num2 - 1>::value;
};

template<int num1>
struct IsPrimeTemplate<num1, 2>
{
	static const bool value = (num1 % 2 != 0);
};

template<>
struct IsPrimeTemplate<1> //1일 때 예외처리
{
	static const bool value = false;
};

template<>
struct IsPrimeTemplate<0> //0일 때 예외처리
{
	static const bool value = false;
};

template <int Numerator, int Denominator = 1>
struct Ratio
{
	using type = Ratio<Numerator, Denominator>; //this 처럼 사용 가능
	const static int n = Numerator;
	const static int d = Denominator;
};

template<Ratio Ratio1, Ratio Ratio2>
struct Add_Ratio
{
	const static Ratio<(Ratio1.n * Ratio2.d + Ratio2.n * Ratio1.d), (Ratio1.d * Ratio2.d)> type;
};

int main()
{
	//Print(1,2,3,1.5,"hello");
	//cout << endl;
	//GetVector<int>(1,2,3,4,5,6,7,8,9);
	//cout << Sum<int>(5,2,3) << "\n"; 
	//cout << SumInt<Int<8>, Int<9>>().value << "\n";
	//cout << FactorialS<3>::value << "\n";
	//cout << GCD(20, 10) << endl;
	//cout << GCDTemplate<20, 10>().value << endl;
	//cout << IsPrime(13) << endl;
	//cout << IsPrimeTemplate<13>().value << endl;
	Ratio<1,2>	ratio1;
	Ratio<2,3> ratio2;
	Add_Ratio<ratio1, ratio2> ratio3;
	cout << ratio3.type.n << "/" <<  ratio3.type.d << endl;
}