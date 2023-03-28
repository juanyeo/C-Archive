#include <iostream>
#include <string>
using namespace std;

int main() {
    string word = { "Debug Console" };
    for (char character : word) { // Range: a sequence of elements, begin(), end()
        cout << character << "/";
    }

    int intArray[5] = {1, 2, 3, 4, 5};
    for (auto element : intArray) { // type deduction
        cout << element << "+";
    }
}