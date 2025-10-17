#include <stdio.h>
#include <stdlib.h>

void inputMatrix(int **matrix, int rows, int cols) {
    printf("Enter elements of the matrix:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("Element [%d][%d]: ", i, j);
            scanf("%d", &matrix[i][j]);
        }
    }
}

void printMatrix(int **matrix, int rows, int cols) {
    printf("The resultant matrix is:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int r1, c1, r2, c2;

    printf("Enter the number of rows in the 1st matrix: ");
    scanf("%d", &r1);
    printf("Enter the number of columns in the 1st matrix: ");
    scanf("%d", &c1);
    printf("Enter the number of rows in the 2nd matrix: ");
    scanf("%d", &r2);
    printf("Enter the number of columns in the 2nd matrix: ");
    scanf("%d", &c2);

    // Check if the matrices can be multiplied
    if (c1 != r2) {
        printf("The matrices cannot be multiplied.\n");
        return 1;
    }

    // Dynamically allocate memory for matrices
    int **matrix1 = (int **)malloc(r1 * sizeof(int *));
    int **matrix2 = (int **)malloc(r2 * sizeof(int *));
    int **result = (int **)malloc(r1 * sizeof(int *));
    for (int i = 0; i < r1; i++) {
        matrix1[i] = (int *)malloc(c1 * sizeof(int));
        result[i] = (int *)malloc(c2 * sizeof(int));
    }
    for (int i = 0; i < r2; i++) {
        matrix2[i] = (int *)malloc(c2 * sizeof(int));
    }

    // Input elements of the first and second matrices
    inputMatrix(matrix1, r1, c1);
    inputMatrix(matrix2, r2, c2);

    // Performing matrix multiplication
    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c2; j++) {
            result[i][j] = 0; // Initialize result matrix element
            for (int k = 0; k < c1; k++) {
                result[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }

    // Print the resultant matrix
    printMatrix(result, r1, c2);

    // Free allocated memory
    for (int i = 0; i < r1; i++) {
        free(matrix1[i]);
        free(result[i]);
    }
    for (int i = 0; i < r2; i++) {
        free(matrix2[i]);
    }
    free(matrix1);
    free(matrix2);
    free(result);

    return 0;
}
