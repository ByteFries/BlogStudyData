//#include <iostream>
//using namespace std;

#define SQUARE(x) (x * x)
#define ADD(x, y) (x + y)
#define INCREASE(x) (x + 1)
int main() {
    ADD(2, 3);         // 정상: 5
    ADD(2.5, 3.5);     // 정상: 6.0
    ADD(2, 3.5);       // 정상: 5.5 (정수와 실수 연산)
    int a = 0;
    int result = INCREASE(a++);
}