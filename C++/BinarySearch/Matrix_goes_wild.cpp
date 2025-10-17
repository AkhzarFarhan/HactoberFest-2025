// You are given an m x n integer matrix matrix with the following two properties:

// -   Each row is sorted in non-decreasing order.
// -   The first integer of each row is greater than last integer of the previous row.
// -   Given an integer target, return true if target is in matrix or false otherwise.
// -   You must write a solution in O(log(m * n)) time complexity.
// Input Format

// - First line contains two integer values, 'm' and 'n', separated by a single space. They represent the 'rows' and 'columns' respectively, for    the two-dimensional array.
// - Second line onwards, the next 'm' lines or rows represent the ith row values.
// - Each of the row constitutes 'n' column values separated by a single space.
// - Target Value

#include<bits/stdc++.h>
#include<iostream>
using namespace std;

bool binsearch(vector<int> a,int l,int r,int target){
    while(l<=r){
        int mid=(l+r)/2;
        if(a[mid]==target){
            return true;
        }
        if(a[mid]>target){
            r=mid-1;
        }
        else{
            l=mid+1;
        }
    }
    return false;
}

int main(){
int m,n;
cin>>m>>n;
vector<int> a(m*n);
for(auto &i : a){
    cin>>i;
}
int target;
cin>>target;
bool ok =binsearch(a,0,n*m-1,target);
cout<<(ok? "true" : "false")<<endl;
return 0;
}