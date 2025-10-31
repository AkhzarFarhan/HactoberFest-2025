import java.util.Scanner;

public class ConvertToBinary {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter a number: ");
        int number = sc.nextInt();

        // Call method to convert to binary
        String binary = toBinary(number);
        System.out.println("Binary representation: " + binary);

        sc.close();
    }

    // Method to convert decimal number to binary
    public static String toBinary(int n) {
        if (n == 0) return "0";

        StringBuilder binary = new StringBuilder();
        while (n > 0) {
            binary.insert(0, n % 2); // prepend remainder
            n /= 2;
        }
        return binary.toString();
    }
}
