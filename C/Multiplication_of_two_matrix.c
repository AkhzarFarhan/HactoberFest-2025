#include<stdio.h>

int main()

{

  int ar[30][30],arr[30][30],i,j,a,b,sum,k,c[30][30];

  printf("\n Enter the no. of rows and columns in matrics : ");

  scanf("%d %d",&a,&b);

  printf("\n Enter the elements of 1st matrix :\n");

  for(i=1;i<=a;i++)

      for(j=1;j<=b;j++)

         scanf("%d",&ar[i][j]); 

  printf("\n first matrix :\n");

  for(i=1;i<=a;i++){

      for(j=1;j<=b;j++)

          printf(" %d",ar[i][j]);

        // if(j=a-1)

          printf("\n");

        }

   printf("\n Enter the elements of second matrix:\n");

   for(i=1;i<=a;i++)

      for(j=1;j<=b;j++)

         scanf("%d",&arr[i][j]); 

   printf("\n Second matrix:\n");

   for(i=1;i<=a;i++){

      for(j=1;j<=b;j++)

         printf(" %d",arr[i][j]);   

         printf("\n");

     

      }

   //multiplication of matrics

   printf("\nMultiplication of given matrics:\n");

   for(i=1;i<=a;i++)

      for(j=1;j<=b;j++)

       {

         sum=0;

          for(k=1;k<=b;k++)

            sum=sum+ar[i][k]*arr[k][j];

         c[i][j]=sum;

       }

     //printf("\nMultiplication of given matrics:");

   for(i=1;i<=a;i++){

      for(j=1;j<=b;j++)

         printf(" %d",c[i][j] );

         printf("\n");

       }

 return 0;

}
