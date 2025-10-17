import java.util.*;
public class sum_of_two_numbers {
    public static void main(String [] args) {
        //Take a Scanner class for taking inputs 
        Scanner sc = new Scanner(System.in);
        // Take inputs a and b 
        int a = sc.nextInt(); 
        int b = sc.nextInt();
        //Initialise integer sum to add a and b 
        int sum = a+ b;
        //Print sum 
        System.out.println(sum);
        sc.close(); //Close the Scanner
    }
}