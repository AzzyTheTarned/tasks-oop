#include <string>
#include <Operator/operator.h>
#include <Stack/stack.h>
using namespace std;

int priority(char oper) {
    int p;
    switch (oper) {
    case '(':
        p = 1;
        break;

    case ')':
        p = 2;
        break;

    case '^':
        p = 5;
        break;

    case '*':
    case '/':
        p = 4;
        break;

    case '+':
    case '-':
        p = 3;
        break;

    default:
        p = 0;
        break;
    }
    return p;
};

string InOPZ(string MyString) {
    Stack *stack = Create();
    string MyStringInOPZ;
    for (int i = 0; i < MyString.length(); i++) {

        if (priority(MyString[i]) == 0) { //  < number >
            MyStringInOPZ += MyString[i];
        }
        if (priority(MyString[i]) == 1) { //  < ( >
            Push(stack, MyString[i]);
        }
        if (priority(MyString[i]) == 2) { //  < ) >
            if (!Empty(stack)) {
                while (Top(stack) != '(') {
                    MyStringInOPZ += Top(stack);
                    Pop(stack);
                }
                Pop(stack);
            }
        }
        if (priority(MyString[i]) > 2) { // < +-*/ >
            if (!Empty(stack)) {
                while (priority(MyString[i]) <= priority(Top(stack))) {
                    MyStringInOPZ += Top(stack);
                    Pop(stack);
                }
            }
            Push(stack, MyString[i]);
        }
    }
    while (!Empty(stack)) {
        MyStringInOPZ += Top(stack);
        Pop(stack);
    }
    return MyStringInOPZ;
}

