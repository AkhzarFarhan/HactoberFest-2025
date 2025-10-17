#include<iostream>
#include<stdlib.h>
using namespace std;
int main()
{
    int a;
    int *p;
    p= new int;
    *p=10;
    cout<<*p<<" "<<&p<<endl;
    //delete p;
    p = new int[20];
    cout<<*p<<" "<<&p<<endl;
    delete[] p;

}
