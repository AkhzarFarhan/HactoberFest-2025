/*
Magic Square Formation:

A Magic Square is an n x n matrix of distinct positive integers from 1 to n²
such that the sum of the numbers in each row, each column, and both main diagonals
is the same (called the magic constant).

The task is to generate a magic square of size n (n is odd) using
the "Siamese method" (a classical backtracking-friendly approach).

Magic Constant Formula: M = n * (n² + 1) / 2

Example:
Input: n = 3
Output:
8 1 6
3 5 7
4 9 2

Each row, column, and diagonal sums to 15.

Note: The Siamese method works only for odd n.
*/
#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

// Function to generate a magic square of size n (odd)
void generateMagicSquare(int n)
{
    if (n % 2 == 0)
    {
        cout << "Magic square generation using this method works only for odd n.\n";
        return;
    }

    vector<vector<int>> magic(n, vector<int>(n, 0));

    int num = 1;
    int i = 0, j = n / 2; // start position

    while (num <= n * n)
    {
        magic[i][j] = num++;
        int newi = (i - 1 + n) % n;
        int newj = (j + 1) % n;

        if (magic[newi][newj] != 0)
            i = (i + 1) % n; // move down if occupied
        else
        {
            i = newi;
            j = newj;
        }
    }

    cout << "Magic Square of size " << n << ":\n";
    for (int r = 0; r < n; r++)
    {
        for (int c = 0; c < n; c++)
            cout << setw(3) << magic[r][c] << " ";
        cout << endl;
    }

    int magicConst = n * (n * n + 1) / 2;
    cout << "\nMagic Constant = " << magicConst << endl;
}

// Driver Code
int main()
{
    int n = 3;
    generateMagicSquare(n);
    return 0;
}
