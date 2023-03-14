#include <ostream>
#include <iostream>
#include <Operator/operator.h>
using namespace std;

int main() {
    string MyString;
    cout << "Enter your string: " << endl;
    cin >> MyString;
    cout << endl;
    cout << "String in RPN: " << InOPZ(MyString) << endl;
}
