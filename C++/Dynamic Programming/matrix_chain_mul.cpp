//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n=nums.size();
        vector<int>padded_nums(n+2,1);
        for(int i =1;i<=n;i++)
            {
                padded_nums[i]=nums[i-1];
            }
        vector<int>;
        for(auto&e:v) if(e>0)v2.push_back(e);
        n=v2.size();
        n+=2;
        vector<pair<int, int>>adjacent_pairs(n-1);
        for(int i=0;i<n-1;i++)
            {
                adjacent_pairs[i]={padded_nums[i],padded_nums[i+1]};
            }
        n--;
        vector<vector<int>>dp(n, vector<int>(n, 0));
        vector<vector<pair<int, int>>>dp_pairs(n, vector<pair<int, int>>(n));
        for(int i=0;i<n;i++)
            {
                dp_pairs[i][i]=adjacent_pairs[i];
            }
        for(int l=2;l<=n;l++)
            {
                for(int i=0;i<n-l+1;i++)
                    {
                        int j=i+l-1;
                        for(int k=i;k<j;k++) 
                        {
                                int a1=dp[i][k], a2=dp[k+1][j];
                            int p=dp_pairs[i][k].first*dp_pairs[i][k].second*dp_pairs[k+1][j].second;
                            if(dp[i][j]>a1+a2+p)
                                {
                                    dp[i][j]=a1+a2+p;
                    int x=dp_pairs[i][k].first,y=dp_pairs[k+1][j].second;
                                   dp_pairs[i][j] ={x, y};
                                }
                        } 
                    }
            }
        return dp[0][n-1];
    }
};
//{ Driver Code Starts.
int main() 
{
   	
   // Matrix Chain Multiplication Cllasical DP Problem
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin>>n;
        vector<int> dims(n);
        for(auto&e:dims)cin>>e;

	    Solution ob;
	    cout << ob.minOperations(dims) << "\n";
	     
    }
    return 0;
}


// } Driver Code Ends