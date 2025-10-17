#include <cmath>
#include <cstdio>
#include <vector>
#include<map>
#include <iostream>
#include <algorithm>
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vll;
// filler value
// should be such that operation(filler_value,a)=a
ll VAL =(1ll<<62ll) - 1ll;
//static array, indexed by [log][starting index]
ll tab[17][100001];
// operation, can be replaced by bitwise OR or min/max function
//Function should be idempotent
//i.e., operation(a,a)=a
ll operation(ll a,ll b)
{
    return (a&b);
}
// 0 based indexing query
ll qry(ll L, ll R) 
    {
    ll len =(R-L+1);
    ll lenlog=log2(len);
    return (tab[lenlog][L] & tab[lenlog][R-(1<<lenlog)+1]) ;
}
// build the sparse table by bottom up dynamic programming
void build(vector<ll>&a,ll &n)
{
        for(int i =0;i<n;i++)tab[0][i]=a[i];
    for(int i =1;i<17;i++)
        {
        for(int j =0;(j+(1<<i))<=n;j++)
            {
            tab[i][j]=operation(tab[i-1][j],tab[i-1][j+(1<<(i-1))]);
        }
    }

}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    //Driver code
    ll n=5;
    vector<ll>a={101,97,84,35,61};
    build(a,n);
    cout<<qry(0,4)<<endl;
    cout<<qry(1,3)<<endl;
    cout<<qry(2,2)<<endl;
}