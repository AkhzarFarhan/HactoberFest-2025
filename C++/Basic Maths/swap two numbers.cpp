#include <iostream>
using namespace std;

int main()
{
    
    int a = 15, b = 100;
    int temp;

    cout << "Before swapping." << endl;
    cout << "a = " << a << ", b = " << b << endl;

    temp=a;
    a=b;
    b=temp;

    cout << "\nAfter swapping." << endl;
    cout << "a = " << a << ", b = " << b << endl;

    return 0;
}
