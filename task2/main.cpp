#include <iostream>
#include <hashtag.h>
using namespace std;

int main() {
    cout << "Input your line:\n";
    string input;
    getline(cin, input);
    cout << hashtag(input);


    return 0;
}