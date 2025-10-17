#include <stdio.h>
#include <string.h>
void main()
{
    int n,i,sum=0;
    char s[100];
    scanf("%s",s);
    n=strlen(s);
    for(i=n;i>=0;i--)
    {
       if(i!=0)
       
        {
           
            if(s[i]=='V' && s[i-1]=='I'){
            sum+=4;
            i--;
            continue;
            }
            else if(s[i]=='X' && s[i-1]=='I'){
            sum+=9;
            i--;
            continue;
            }
      
             else if(s[i]=='L' && s[i-1]=='X'){
             sum+=40;
             i--;
             continue;
            }
      
             else if(s[i]=='C' && s[i-1]=='X'){
              sum+=90;
              i--;
              continue;
                }
              else if(s[i]=='D'&& s[i-1]=='C'){
            sum+=400;
            i--;
            continue;
            }
      
            else if(s[i]=='M' && s[i-1]=='C'){
             sum+=900;
             i--;
             continue;
             }
        }
       
            
         if(s[i]=='I')
        sum+=1;
        else if(s[i]=='V')
        sum+=5;
        else if(s[i]=='X')
        sum+=10;
        else if(s[i]=='L')
        sum+=50;
        else if(s[i]=='C')
        sum+=100;
        else if(s[i]=='D')
        sum+=500;
        else if(s[i]=='M')
        sum+=1000;
          
       
    }
  
 printf("\n%d",sum);
    
}