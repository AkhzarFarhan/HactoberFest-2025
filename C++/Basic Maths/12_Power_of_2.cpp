#include <iostream>
using namespace std;

bool Power_of_2(int n){
    if(n==0){
        return false;
    }
    while(n!=1){
        if(n%2==1){
            return false;
        }
        n=n/2;
    }
    return true;
}

// Efficient Method
bool isPower2(int n){
    if (n==0 )return false;
    return ((n&(n-1))==0);
}

// One liner
bool power(int n){
    return (n!=0) && ((n&(n-1))==0);
}


int main(){
    int n;
    cin>>n;
    cout<<Power_of_2(n)<<endl;
    cout<<isPower2(n)<<endl;
    cout<<power(n);
    return 0;
}