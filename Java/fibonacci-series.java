// FibonacciSeries.java
// Program to print Fibonacci Series using both Recursion and Iteration

import java.util.Scanner;

public class FibonacciSeries {

    // Recursive approach
    static int fibonacciRecursive(int n) {
        if (n <= 1)
            return n;
        return fibonacciRecursive(n - 1) + fibonacciRecursive(n - 2);
    }

    // Iterative approach
    static void fibonacciIterative(int n) {
        int first = 0, second = 1;
        System.out.print("Iterative Fibonacci Series: ");
        for (int i = 0; i < n; i++) {
            System.out.print(first + " ");
            int next = first + second;
            first = second;
            second = next;
        }
        System.out.println();
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter the number of terms: ");
        int n = sc.nextInt();

        // Iterative version
        fibonacciIterative(n);

        // Recursive version
        System.out.print("Recursive Fibonacci Series: ");
        for (int i = 0; i < n; i++) {
            System.out.print(fibonacciRecursive(i) + " ");
        }
        System.out.println();

        sc.close();
    }
}
