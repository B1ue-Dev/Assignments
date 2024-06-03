// C++ Program to demonstrate
// use of references
#include <iostream>
using namespace std;

int main()
{
    int x = 10;

    // No reference &
    int ref = x;
    ref = 20;
    cout << "x = " << x << '\n';
    cout << "ref = " << ref << '\n';

    // There is reference &
    int& ref2 = x;
    ref2 = 20;
    cout << "x = " << x << '\n';
    cout << "ref = " << ref2 << '\n';

    return 0;
}
