#include <iostream>
#include <RingBuff.h>
using namespace std;

int main() {
    List _head;
    int n = 10;     //number of slots
    _head.init(n);
    for (int i = 1; i < 20; i++) {  //number of digits
        _head.add((char)i);
        _head.Print(std::cout);
    }
    return 0;
}
