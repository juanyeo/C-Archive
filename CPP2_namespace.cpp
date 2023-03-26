#include <iostream>

// namespace one, two 안에 이름이 같은 값, 함수가 있어도 구별해서 사용 가능
namespace one {
    int A = 11; // 값
    int value() { return 1; } // 함수
}

namespace two {
    const double A = 12.0;
    double value() { return 2.2; }
}
int T = 38;

using namespace std; // std:: 없이 바로 쓸 수 있음
int main () {
    cout << one::value() << '\n'; // 1
    
    using two::value; // 특정 요소에 접근 -> 함수 내부에 한정
    cout << value() << '\n'; // 2.2
    
    one::A = 23;
    namespace first = one; // namespace aliasing - 별칭 설정
    using namespace first; // 모든 요소에 접근 -> 함수 내부에 한정
    cout << A << " & " << two::A << '\n'; // 11 & 12
    return 0;
}