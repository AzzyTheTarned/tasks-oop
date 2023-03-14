#include <iostream>
#include <base64.h>
using namespace std;

int main() {
    cout << endl;
    cout << b64encode("ABOBA");
	cout << endl;
    cout << b64decode("SQ==");
    cout << endl;


    return 0;
}
