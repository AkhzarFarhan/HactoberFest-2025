#include <bits/stdc++.h>
using namespace std;

int count_subsets(int arr[], int n, int sum)
{
    vector<vector<int>> t(n + 1, vector<int>(sum + 1));

    for (int i = 0; i < n + 1; i++)
    {
        for (int j = 0; j < sum + 1; j++)
        {
            if (j == 0)
                t[i][j] = 1;
            else if (i == 0)
                t[i][j] = 0;

            else if (arr[i - 1] > j)
                t[i][j] = t[i - 1][j];

            else
                t[i][j] = t[i - 1][j] + t[i - 1][j - arr[i - 1]];
        }
    }

    return t[n][sum];
}
int main()
{
    int arr[] = {2, 3, 5, 6, 8, 10};
    int sum = 10;
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << count_subsets(arr,n,sum);
    return 0;
}