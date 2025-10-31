import java.util.Scanner;
import java.util.Stack;

/**
 * Program to check if a string has balanced parentheses.
 * Supports (), {}, and [].
 */
public class BalancedParenthesis {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.print("Enter a string containing parentheses: ");
        String s = sc.nextLine();

        Stack<Character> stack = new Stack<>();
        boolean balanced = true;

        // Traverse the string character by character
        for (int i = 0; i < s.length(); i++) {
            char ch = s.charAt(i);

            // If opening bracket, push to stack
            if (ch == '(' || ch == '{' || ch == '[') {
                stack.push(ch);
                continue;
            }

            // If stack is empty and closing bracket found → unbalanced
            if (stack.isEmpty()) {
                balanced = false;
                break;
            }

            // Check for matching closing brackets
            if (ch == ')' && stack.peek() == '(') {
                stack.pop();
            } else if (ch == ']' && stack.peek() == '[') {
                stack.pop();
            } else if (ch == '}' && stack.peek() == '{') {
                stack.pop();
            } else if (ch == ')' || ch == ']' || ch == '}') {
                balanced = false;
                break;
            }
        }

        // If stack not empty at the end → unbalanced
        if (!stack.isEmpty()) {
            balanced = false;
        }

        // Print result
        if (balanced) {
            System.out.println("The parentheses are balanced.");
        } else {
            System.out.println("The parentheses are not balanced.");
        }

        sc.close();
    }
}
