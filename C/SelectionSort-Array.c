#include <stdio.h>
#include<stdlib.h>

int main()
{
	int n;
	
	printf("Enter array size :");
	scanf("%d",&n);
	
	int *a=(int*)malloc(n*sizeof(int));
	
	printf("Enter array elements : \n",n);
	
	for(int i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	
	printf("Original array \n");
	
	for(int i=0;i<n;i++)
		printf("%d  ",a[i]);
		
	for(int i=0; i<n-1; ++i)
	{
		int minI=i;
		for(int j=i+1; j<n;++j)
		{
			if (a[j]<a[minI])
				minI=j;
			if(minI!=i)
			{
				int temp=a[minI];
				a[minI]=a[i];
				a[i]=temp;
			}
		}
	}
	printf("\nAfter sorting: \n");
	
	for(int i=0;i<n;i++)
		printf("%d  ",a[i]);
	return 0;
}
