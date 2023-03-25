#include <iostream>
#include <string> // string
#include <sstream> // string stream

/*
Stream : source/destination of characters, sequentially
I/O grammer : cin(keyboard), cout(screen), endl(='\n'), cerr, clog
*/
int main(void) {
    int A;
    std::string B, C;
    std::cin >> A; // cin automatically matches type
    std::cin >> B; // "My Room" -> only save "My" (single word, space)
    getline(std::cin, C); // "My Room" -> "My Room"

    std::cout << "Variable A : " << A << '\n'; // flush automatically
    std::cout << "Variable B : " << B << std::endl; // flush immediately
    std::cout << "Variable C : " << C << std::endl;

    std::string stringInt = "1024";
    std::stringstream(stringInt) >> A; // String to Int
}