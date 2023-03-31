#include <iostream>
using namespace std;

class Graduate {
        int credit; // private 값
        double grade1;
        double grade2;
        double averageGrades(); // private 메서드
    public: // public 메서드(값) -> Access Specifiers : '컴파일 단계'에서만 사용됨
        Graduate() {
            credit = 0;
            grade1 = 3.0;
            grade2 = 3.0;
        };
        Graduate(int a, double b, double c);
        ~Graduate();
        void printGraduate(char* name);
};

// Constructor : 클래스가 new로 만들어졌을 때 자동 호출 (파이썬 __init__)
// No Return (리턴 타입도 안쓴다)
Graduate::Graduate(int _credit, double _grade1, double _grade2)
    : grade1(_grade1), grade2(_grade2) { // A::A(파라미터): 파라미터(값) 자동 대입
    // ^ initialized directly, initialization list(안에서 constructor 호출 가능)
    credit = _credit; // 직접 대입
}
// Destructor
Graduate::~Graduate() { cout << "Bye!" << endl; }

double Graduate::averageGrades() { return (grade1 + grade2) / 2; }
void Graduate::printGraduate(char* name) { // self, this처럼 클래스 객체가 자동으로 들어옴
    cout << "Credit : " << credit << '\n'; // 클래스 variable 사용
    cout << "Grade : " << averageGrades() << '\n'; // 다른 메서드 사용
    if (credit >= 30 && averageGrades() > 3.0) {
        cout << name << " can Graduate this school" << endl;
    } else {
        cout << name << " cannot Graduate this school" << endl;
    }
    
}

// 클래스를 템플릿 타입으로 만들 수 있음
template <class AnyClass>
class Pair {
    AnyClass pair[2];
    public:
        Pair(AnyClass first, AnyClass second) {
            pair[0] = first;
            pair[1] = second;
        }
        AnyClass add(); // 메소드도 템플릿으로 만들 수 있음
};

// 메소드는 function template을 사용해 정의되어야 한다
template <class AnyClass>
AnyClass Pair<AnyClass>::add() {
    return pair[0] + pair[1];
}

int main(void) {
    Graduate graduate1; // 오브젝트 Stack에 할당됨 
    Graduate graduate2(33, 3.0, 4.5); // 오브젝트 Stack에 할당됨
    Graduate* graduate3 = new Graduate(12, 3.0, 3.5); // Heap의 memory block 가르킨다
    
    graduate1.printGraduate("Kim");
    graduate2.printGraduate("Min");
    (*graduate3).printGraduate("David");
    // graduate1.averageGrades(); -> private 메서드여서 inaccessible, 컴파일 불가

    Pair<int> pair1(12, 14);
    Pair<double> pair2(12.2, 14.5);

    cout << pair1.add() << '\n';
    cout << pair2.add() << '\n';
}