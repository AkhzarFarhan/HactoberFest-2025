#include <stdio.h>
int main(){
    int row,col,count=0;
    printf("Enter the number of rows and columns of 1st matrix : ");
    scanf("%d %d", &row, &col);
    int arr[row][col];
    for(int i = 0; i <row; i++){
        for(int j = 0; j <col; j++){
            scanf("%d",&arr[i][j]);
        }
    }
    int row1,col1;
    printf("\nEnter the number of rows and columns of 2nd matrix : ");
    scanf("%d %d", &row1, &col1);
    int arr1[row1][col1];
    for(int i = 0; i <row1; i++){
        for(int j = 0; j <col1; j++){
            scanf("%d",&arr1[i][j]);
        }
    }

    if (row1!=row || col1!=col){
        printf("\nMatrices are not identical");
    }
    else {
        if (row1==row && col1==col){
            for(int i = 0; i <row1; i++){
                for(int j = 0; j <col1; j++){
                    if(arr1[i][j]==arr[i][j]){
                        count+=1;  
                    }
                }
        
            }
            int a = row*col;
            if (count==a){
                printf("\nMatrices are identical");
            }
            else{
                printf("\nMatrices are not identical");
            }

        }
    }
}