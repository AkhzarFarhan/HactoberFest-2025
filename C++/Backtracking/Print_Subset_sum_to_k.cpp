/* Given an array A and an integer K, print all subsets of A which sum to K.
Subsets are of length varying from 0 to n, that contain elements of the array. But the order of elements 
should remain same as in the input array.
Input - Line 1 : Size of input array
        Line 2 : Array elements separated by space
        Line 3 : K 
*/
#include<bits/stdc++.h>
using namespace std;
void print(vector<int> temp)
{
    for(int i=0;i<temp.size();i++)
    {
        if(i!=temp.size()-1)
            cout<<temp[i]<<" ";
        else
            cout<<temp[i];
    }
    cout<<endl;
}
bool check(vector<int> temp,int k)
{
    int sum=0;
    for(int i=0;i<temp.size();i++)
        sum=sum+temp[i];
    return(sum==k);
}
void subset(int input[],int n,int k,vector<int> temp)
{
    if(n==0)
    {
        if(check(temp,k))
            print(temp);
        return;
    }
    temp.push_back(input[0]);
    subset(input+1,n-1,k,temp);
    temp.pop_back();
    subset(input+1,n-1,k,temp);
}
void printSubsetSumToK(int input[], int size, int k) {
    // Write your code here
    vector<int> temp;
    subset(input,size,k,temp);
}
int main() {
  int input[1000],length,k;
  cin >> length;
  for(int i=0; i < length; i++)
    cin >> input[i];
  cin>>k;
  printSubsetSumToK(input, length,k);
}