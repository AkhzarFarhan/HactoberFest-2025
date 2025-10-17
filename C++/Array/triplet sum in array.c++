#include <iostream>
#include <vector> 
#include <algorithm>
using namespace std;

bool find3Numbers(vector<int>& arr, int sum)
{
    int n = arr.size();
    
    sort(arr.begin(), arr.end());

    for (int i = 0; i < n - 2; i++) {

      
        int l = i + 1;  
                        
        int r = n - 1;  

        while (l < r) {
            int curr_sum = arr[i] + arr[l] + arr[r];
            if (curr_sum == sum) {
                cout << "Triplet is " << arr[i] << ", "
                    << arr[l] << ", " << arr[r];
                return true;
            } else if (curr_sum < sum)
                l++;
            else 
                r--;
        }
    }
  
    return false;
}

int main()
{
    vector<int> arr = { 1, 4, 45, 6, 10, 8 };
    int sum = 22;
    find3Numbers(arr, sum);
    return 0;
}