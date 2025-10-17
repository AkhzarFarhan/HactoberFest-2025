package FrequentPrograms;

import java.util.Scanner;

public class ArmstrongNumberUsingWhile {
	private static Scanner sc;
	
	public static void main(String[] args) {
		int Number, Temp, Reminder, Times = 0;
		double Sum = 0;
		sc = new Scanner(System.in);		
		System.out.println("\n Please Enter number to Check for Armstrong: ");
		Number = sc.nextInt();

		//Helps to prevent altering the original value
		Temp = Number;
		/*
		 * The 'Times' variable is used to store the number of digits in the number,
		 * which can then be used to check for Armstrong Number
		 */
		while (Temp != 0) {
			Times = Times + 1;
			Temp = Temp / 10;
		}

		Temp = Number;

		/*
		 * The 'Sum' is calculated by adding each digit of the number raised to a power
		 * equal to the number of digits in the number, i.e. the 'Times' value
		 */
		while( Temp > 0)  {
			Reminder = Temp %10;
		    Sum = Sum + Math.pow(Reminder, Times);
		    Temp = Temp /10;
		}
		System.out.format("\n Sum of entered number is = %.2f", Sum);
		
		/*
		 * If the calculated value of 'Sum' is equal to the original number, then the number is
		 * Armstrong, otherwise it is not
		*/
		if (Sum == Number) {
			System.out.format("\n% d is a Armstrong Number", Number);
		}
		else {
			System.out.format("\n% d is NOT a Armstrong Number", Number);
		}
	}
}
