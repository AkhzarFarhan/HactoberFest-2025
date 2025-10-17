QUESTION :
_______________________________________________________________________
You are given number of pages in n different books and m students. The books are arranged in ascending order of number of pages. Every student is assigned to read some consecutive books. The task is to assign books in such a way that the maximum number of pages assigned to a student is minimum.

Input Format
First line contains integer t as number of test cases. Next t lines contains two lines. For each test case, 1st line contains two integers n and m which represents the number of books and students and 2nd line contains n space separated integers which represents the number of pages of n books in ascending order.

Constraints
1 < t < 50
1< n < 100
1< m <= 50
1 <= Ai <= 1000

Output Format
Print the maximum number of pages that can be assigned to students.

Sample Input
1
4 2
12 34 67 90
Sample Output
113 
-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
SOLUTION :
__________________________________________________________________________
#include<bits/stdc++.h>
using namespace std;
bool isPossible(int a[],int n, int m, int mid){
	 int student=1;
	 int pages= 0;
	 for(int i=0;i<n;i++){
		 if(mid<(pages+a[i])){
			 student++;
			 pages=a[i];
			 if(student>m)
			 return false;
		 }
		 else{
			 pages+=a[i];
		 }
	 }
	 return true;
}
int main() {
	int t;
	cin>>t;
	while(t-->0){
	int n;
	cin>>n;
	int student;
	cin>>student;
	int pages[n];
	int sum=0;
	for(int i=0;i<n;i++){
		cin>>pages[i];
		sum+=pages[i];
	}
	
	int s=pages[n-1];
	
	int e=sum;
	int ans=INT_MAX;
	while(s<=e){
		int mid=(s+e)/2;
		if(isPossible(pages,n,student,mid)){
          ans=min(ans,mid);
		  e=mid-1;
		}
		else{
			s=mid+1;
		}
	}
     cout<<ans<<endl;
	}return 0;
}
