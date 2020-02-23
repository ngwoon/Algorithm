#include <iostream>

using namespace std;

int main(void) {
    unsigned long long temp1 = 1;
    unsigned long long temp2 = 1;

    for(int i=39; i>=20; i--)
        temp1 *= i;

    for(int i=20; i >= 1; i--)
        temp2 *= i;

    cout << temp1 << endl;
    cout << temp2 << endl;

    cout << temp1 / temp2 << endl;

    return 0;
}