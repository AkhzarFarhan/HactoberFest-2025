import java.util.Scanner;

public class MatrixMultiplication {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        // Input for the first matrix
        System.out.print("Enter rows and columns for first matrix: ");
        int rows1 = sc.nextInt();
        int cols1 = sc.nextInt();
        int[][] matrix1 = new int[rows1][cols1];

        System.out.println("Enter elements of first matrix:");
        for (int i = 0; i < rows1; i++) {
            for (int j = 0; j < cols1; j++) {
                matrix1[i][j] = sc.nextInt();
            }
        }

        // Input for the second matrix
        System.out.print("Enter rows and columns for second matrix: ");
        int rows2 = sc.nextInt();
        int cols2 = sc.nextInt();

        // Check if multiplication is possible
        if (cols1 != rows2) {
       // If Number of Columns of first Matrix is not equal to Number of Rows of second Matrix , then Multiplication is not possible.
            System.out.println("Matrix multiplication not possible.");
            return ;
        }

        int[][] matrix2 = new int[rows2][cols2];

        System.out.println("Enter elements of second matrix:");
        for (int i = 0; i < rows2; i++) {
            for (int j = 0; j < cols2; j++) {
                matrix2[i][j] = sc.nextInt();
            }
        }

        // Matrix multiplication
        int[][] result = new int[rows1][cols2];
        for (int i = 0; i < rows1; i++) {
            for (int j = 0; j < cols2; j++) {
                for (int k = 0; k < cols1; k++) {
                    result[i][j] += matrix1[i][k] * matrix2[k][j];
                }
            }
        }

        // Output the result
        System.out.println("Resultant Matrix:");
        for (int i = 0; i < rows1; i++) {
            for (int j = 0; j < cols2; j++) {
                System.out.print(result[i][j] + " ");
            }
            System.out.println();
        }

        sc.close();
    }
}
