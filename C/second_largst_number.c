#include<stdio.h>
/*a program find the second largest number of n numbers using array */
int main()
{
    int a[100],i,n,largest,seclargest;
    printf("enter the no of element");
    scanf("%d",&n);
    printf("enter the numbers");
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    largest=a[0];
    for(i=1;i<n;i++)
    {
        if(largest<a[i])
        largest=a[i];

    }
    seclargest=a[0];
    for(i=1;i<n;i++)
    {

        if(seclargest<a[i])
    {
        if(a[i]==largest)
            continue;
        seclargest=a[i];

    }
    }
    printf("seclargest number is %d",seclargest);
}
