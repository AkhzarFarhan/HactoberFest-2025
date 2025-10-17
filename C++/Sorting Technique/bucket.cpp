#include <bits/stdc++.h>
using namespace std;

//Start of bucketSort function.
void bucketSort(float arr[], int n)
{
	vector<float> b[n];

	for (int i = 0; i < n; i++)
	{
		int ind = n * arr[i];
		b[ind].push_back(arr[i]);
	}

	for (int i = 0; i < n; i++)
		sort(b[i].begin(), b[i].end());

	int new_ind = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < b[i].size(); i++)
			arr[new_ind++] = b[i][j];
}

int main()
{
	int n;
	float arr[100000];

	cout << "Enter number of elements" << endl;
	cin >> n;

	for (int i = 0; i < n; i++)
		arr[i] = (rand() % 1000) * 0.001;

	clock_t time_req;

	time_req = clock();
	bucketSort(arr, n);
	time_req = clock() - time_req;
	double time_taken_bucket = (double)time_req / CLOCKS_PER_SEC;

	cout << "Sorted array is " << endl;

	for (int i = 0; i < n; i++)
		cout << arr[i];

	cout << "Time taken by bucket sort is" << fixed << setprecision(9) << time_taken_bucket << endl;
}
