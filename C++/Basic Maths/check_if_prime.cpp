// Clean solution for checking if number is prime

// Author - Himanshu Gwalani (Himanshu-g81)

#include<bits/stdc++.h>
using namespace std;

bool isPrime(int n) 
{ 
    bool isPrime = true;

    // 0 and 1 are not prime numbers
    if (n == 0 || n == 1) {
        isPrime = false;
    }
    else {
        for (int i = 2; i <= n / 2; ++i) {
            if (n % i == 0) {
                isPrime = false;
                break;
            }
        }
    }
    return isPrime;
}
int main()
{
	int n;
	cout << "Enter a number : ";
	cin >> n;

	if(isPrime(n)) {
		cout << "It is prime" << endl;
	} else {
		cout << "It is NOT prime" << endl;
	}
}
