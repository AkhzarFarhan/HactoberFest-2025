#include <bits/stdc++.h>
using namespace std;

//This program will help you to check if a number is prime or not in O(sqrt(n)).

bool is_prime(int x)
{
    if(x<=1)
        return false;
    if(x==2||x==3)
        return true;
    if(x%2==0 || x%3==0)
        return false;
    for(int i=5;i<=sqrt(x);i+=6)
        {
            if(x%i==0 || x%(i+2)==0)
                return false;
        } 
    return true;
}

int main()
{
    int n;
    cout<<"Enter a number ";
    cin>>n;
    if(is_prime(n))
    {
        cout<<"Number is prime";
    }
    else
    {
        cout<<"Number is not prime";
    }    
    return 0;
}
