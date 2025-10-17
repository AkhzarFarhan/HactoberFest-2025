#include <iostream>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
    
        unordered_map <char,int> ump;
            
        int mx=0,x=0;
        for(int i=0;i<s.size();i++){
            if(ump[s[i]]==0){
                ump[s[i]]++;
                x++;
            }else{
                mx = max(mx,x);
                //back to (i-x) index for relooping from the double occurance
                if(x>0) i-=x;
                x=0;
                ump.clear();
            }
        }
        mx = max(x,mx);
        return mx;
        
    }
};
