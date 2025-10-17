// C++ program to count number of
// ways to reach Nth stair
#include <bits/stdc++.h>
using namespace std;
 
// A simple recursive program to
// find N'th fibonacci number
int fib(int n)
{
    if (n <= 1)
        return n;
    return fib(n - 1) + fib(n - 2);
}
 
// Returns number of ways to
// reach s'th stair
int countWays(int s)
{
    return fib(s + 1);
}
 
// Driver C
int main()
{
    int s = 4;
 
    cout << "Number of ways = " << countWays(s);
 
    return 0;
}
 
