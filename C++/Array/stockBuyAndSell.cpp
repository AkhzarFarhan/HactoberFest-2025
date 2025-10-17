class Solution{
public:
    //Function to find the days of buying and selling stock for max profit.
    vector<vector<int> > stockBuySell(vector<int> A, int n){
        // code here
        vector<vector<int>> ans;
        
        for(int i = 0; i < n-1; i++){
            if(A[i] < A[i+1]){
                ans.push_back({i,i+1});
            }
        }
        
        return ans;
    }
};
