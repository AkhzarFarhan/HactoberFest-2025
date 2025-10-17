#include<iostream>
using namespace std;
class Solution
{
    public:
    //Function to find the maximum occurring character in a string.
    char getMaxOccuringChar(string str)
    {
        
        // Your code here
        int arr[26]={0};
        for(int i=0;i<str.length();i++)
        {
            char ch=str[i];
            int number=0;
            if(ch>='a' && ch<='z')
            {
                number=ch-'a';
            }
            arr[number]++;
        }
        int maxi=-1;
        int ans=0;
        for(int i=0;i<26;i++)
        {
            if(arr[i]>maxi)
            {
                ans=i;
                maxi=arr[i];
            }
        }
        int result=ans+'a';
        return result;
        
    }

};



int main()
{
   
    int t;
    cin >> t;
    while(t--)
    {
        string str;
        cin >> str;
    	Solution obj;
        cout<< obj.getMaxOccuringChar(str)<<endl;
    }
}
