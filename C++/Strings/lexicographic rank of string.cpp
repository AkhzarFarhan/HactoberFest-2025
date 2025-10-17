// C++ program to find lexicographic rank
// of a string
#include <bits/stdc++.h>
using namespace std;

// Factorial
int fact(int n) { 
    int res = 1;
    for (int i = 2; i <= n; i++) { res *= i; }
    return res;
}

// A utility function to count
// smaller characters on right of arr[low]
int findSmallerInRight(string str, int low)
{
    int countRight = 0;
    for (int i = low + 1; i < str.size(); ++i)
        if (str[i] < str[low])
            ++countRight;
    return countRight;
}

// A function to find rank of a string
// in all permutations of characters
int findRank(string str)
{
    int n = str.size();
    int rank = 1;  // 1 to be added to smaller count
    int countRight;

    for (int i = 0; i < n; ++i) {

        // Count number of chars smaller than str[i]
        // from str[i+1] to str[len-1]
        countRight = findSmallerInRight(str, i);

        rank += countRight * fact(n - i - 1);
    }

    return rank;
}

// Driver code
int main()
{
    string str = "string";
    cout << findRank(str);
    return 0;
}
