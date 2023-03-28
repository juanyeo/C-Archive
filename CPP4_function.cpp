#include <iostream>
using namespace std;

/*
    1. call by value / call by reference (+ Advanced version, Const)
    2. function overloading (+ default parameter value)
    3. function template (+ Non-Type Template)
*/

// void swap(int x, int y) -> call by value: 값 안바뀜, 안전함
// void swap(int* x, int* y) -> call by reference: 주소 넘김, 메모리 효율적
void swap(int* x, int* y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

// + void swap_const(const int &x, const int &y)하면 '컴파일 단계'에서 에러 (read-only)
// const 쓰면 메모리도 효율적
void swap_advanced(int &x, int &y) {
    int temp = x; // x의 값 대입
    x = y; // 자동으로 x 주소 연결
    y = temp;
}

// function overloading : C(X) C++(O) 같은 이름 but 파라미터, 리턴값 다름
int calculate(int a, int b=1) { return a + b; } // parameter 기본값 C(X) C++(O)
int calculate(int a, int b, int c) { return a + b - c; }
double calculate(double a, double b) { return a * b; }

// function template : generic type
template <class AnyClass>
AnyClass calculate_generic(AnyClass a, AnyClass b) {
    return a + b;
}
template <class AnyClass, int N>
AnyClass calculate_generic_fixed(AnyClass a) {
    return a * N;
}

int main(void) {
    int A = 2, B = 5;

    swap(&A, &B); // A: 5, B: 2
    swap_advanced(A, B); // A: 2, B: 5

    calculate(3); // 기본값 b=1 -> 4
    calculate(3.0, 4.0); // 12

    // AnyClass의 타입 < > 안에 명시
    calculate_generic<int>(1, 4); // 5 
    calculate_generic<double>(1.1, 4.2); // 5.3
    calculate_generic(1.4, 2.1); // parameter deduction, 3.5
    calculate_generic_fixed<double, 3>(1.2); // 3.6
    // N 값을 바꿀 때마다 '컴파일 단계'에서 함수 여러개 만들어짐, calculate(1.2, 3)과 다름 
}