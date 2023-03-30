#include <iostream>
using namespace std;

int main(void) {
    int* array;

    // 메모리 할당 - 아래 두 줄은 동일한 기능을 한다
    array = new int[5];
    array = (int*) malloc(sizeof(int) * 5 + 4); // + 4 byte는 크기 저장

    // Exception - C(X) C++(O) / compile time(X) runtime(O) 
    array = new int[5]; // 실패 시 프로그램 중지
    array = new (nothrow) int[5]; // 실패 시 null pointer 반환
    if (array == nullptr) { } // Exception 직접 처리

    // free와 같은 역할
    delete[] array; // 사이즈 4 byte에 저장되어 있으므로 delete에 따로 입력 불필요
}