#include<stdio.h>
#include<stdlib.h>

void swap(int *x, int *y)
{
    int temp;
    temp=*x;
    *x=*y;
    *y=temp;
}

void SelectionSort(int A[],int n)
{
    int i, j, k;

    for(i=0; i<n-1; i++)
    { 

        for(j=k=i; j<n; j++)
        {
            if(A[j]<A[k])
            {
                k=j;
            }
        }
        swap(&A[i],&A[k]);
    }
}

int main()
{
    int *p, num ,i;
    
    printf("Enter the number of elements to sort: ");
    scanf("%d",&num);
    p=(int*) malloc(num * sizeof(int));
    printf("\nPut the numbers: ");
    for(i=0; i<num; i++)
    {
        scanf("%d",(p+i)); 
    }
    SelectionSort(p,num);

    printf("\n");
    for(i=0; i<num; i++)
    {
        printf("%d\t",*(p+i));
    }
    free(p);
    return 0;
}
