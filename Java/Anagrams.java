import java.util.Scanner;

/**
 * Program to check if two strings are anagrams of each other.
 * Two strings are anagrams if they contain the same characters with the same frequency.
 */
public class Anagrams {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        // Input two strings
        System.out.print("Enter first string: ");
        String a = sc.next();

        System.out.print("Enter second string: ");
        String b = sc.next();

        boolean isAnagram = false;

        // Array to mark visited characters in the second string
        boolean[] visited = new boolean[b.length()];

        // Check only if lengths are equal
        if (a.length() == b.length()) {
            for (int i = 0; i < a.length(); i++) {
                char c = a.charAt(i);
                isAnagram = false;

                // Check if the current character exists in the second string
                for (int j = 0; j < b.length(); j++) {
                    if (b.charAt(j) == c && !visited[j]) {
                        visited[j] = true; // mark character as used
                        isAnagram = true;
                        break;
                    }
                }

                // If character not found, not an anagram
                if (!isAnagram) break;
            }
        }

        // Output result
        if (isAnagram) {
            System.out.println("The strings are anagrams.");
        } else {
            System.out.println("The strings are not anagrams.");
        }

        sc.close();
    }
}
