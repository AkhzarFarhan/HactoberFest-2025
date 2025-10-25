import java.util.Scanner;

public class Factorial {
    public static void main(String[] args) {
        Scanner stdin = new Scanner(System.in);
        System.out.println("Java program to find factorial of a number");

        // Read the number from the user
        System.out.print("Enter a number to find its factorial: ");
        int number = stdin.nextInt();

        long fac = factorial(number); // Call static method
        System.out.println("Factorial of " + number + " is " + fac);

        stdin.close();
    }

    // Static method to calculate factorial
    public static long factorial(int n) {
        long factorial = 1;
        for (int i = 1; i <= n; i++) {
            factorial *= i;
        }
        return factorial;
    }
}
