//#include <iostream>
//using namespace std;

#define SQUARE(x) (x * x)
#define ADD(x, y) (x + y)
#define INCREASE(x) (x + 1)
int main() {
    ADD(2, 3);         // ����: 5
    ADD(2.5, 3.5);     // ����: 6.0
    ADD(2, 3.5);       // ����: 5.5 (������ �Ǽ� ����)
    int a = 0;
    int result = INCREASE(a++);
}