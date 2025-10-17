#include <iostream>
 using namespace std;
 
 int main(){
 	cout<<"Enter the value of n: ";
 	int n;
 	cin>>n;
 	
 	int count=1;
 	for(int i=1;i<=n;i++){
 		for(int j=1;j<=i;j++){
 			cout<<count<<" ";
 			count++;
		 }
		cout<<endl; 
	 }
 	
 }