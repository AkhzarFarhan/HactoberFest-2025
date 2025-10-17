// A binary search C program using pointers.
#include<stdio.h>
int binarysearch(int *arr, int ele, int *ptrlast, int **ptr_to_value);
int main()
{ int arr[20],n,i;
  int found,value;
  int *ptrlast,*ptr_to_value;
  int ele;
  ptr_to_value=NULL;
  printf("Enter the number of elements");
  scanf("%d",&n);
  printf("Enter the elements");
  for(i=0;i<n;i++)
  scanf("%d",&arr[i]);
  printf("Enter the element to be searched");
  scanf("%d",&ele);
  ptrlast=arr+n-1;
  found=binarysearch(arr,ele,ptrlast,&ptr_to_value);
  found?printf("Element %d is found",*ptr_to_value):printf("Element is not found");
  return 0;
}
int binarysearch(int *arr, int ele, int *ptrlast, int **ptr_to_value)
{ int *firstptr, *midptr, *lastptr;
  firstptr=arr;
  lastptr=ptrlast;
  while(firstptr<=lastptr)
  { midptr = firstptr+(lastptr-firstptr)/2;
    if(ele>*midptr)
      { firstptr=midptr+1;
      }
    else if(ele<*midptr)
      {
        lastptr=midptr-1;
      }
    else
      {
          firstptr=lastptr+1;
      }


  }
*ptr_to_value=midptr;
 return(ele==*midptr);

}
