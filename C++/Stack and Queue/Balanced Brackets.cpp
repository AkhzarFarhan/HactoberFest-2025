#include <bits/stdc++.h>

using namespace std;

bool isbalanced(string s)
{
    int n=s.length();
    stack<char> st;
    bool ans=true;
    for(int i=0;i<n;i++)
    {
        if(s[i]=='(' || s[i]=='{' || s[i]=='[')
        {
            st.push(s[i]);
        }
        else if(s[i]==')')
        {
            if(!st.empty() && st.top()=='(')
            {
                st.pop();
            }
            else
            {
                ans=false;
                break;
            }
        }
        else if(s[i]=='}')
        {
            if(!st.empty() && st.top()=='{')
            {
                st.pop();
            }
            else
            {
                ans=false;
                break;
            }
        }
        else if(s[i]==']')
        {
            if(!st.empty() && st.top()=='[')
            {
                st.pop();
            }
            else
            {
                ans=false;
                break;
            }
        }
        
    }
    if(!st.empty())
    {
        return false;
    }
    
    return ans;
    
    
}



int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string s;
    cin>>s;
    if(isbalanced(s))
    {
        cout<<"YES"<<endl;
    }
    else {
    cout<<"NO"<<endl;
    }
    }
    
    return 0;
}