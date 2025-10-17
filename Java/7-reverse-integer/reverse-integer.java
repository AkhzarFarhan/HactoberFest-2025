class Solution {
    public int reverse(int x) {
        // Variable to store the reversed number
        int ans = 0;

        // Loop runs until all digits are processed
        while (x != 0) {
            // Extract the last digit from x
            int digit = x % 10;

            // Check for overflow/underflow before multiplying by 10
            // If reversed number is about to go beyond integer range → return 0
            if ((ans > Integer.MAX_VALUE / 10) || (ans < Integer.MIN_VALUE / 10)) {
                return 0;
            }

            // Add the digit to the reversed number
            ans = (ans * 10) + digit;

            // Remove the last digit from x
            x = x / 10;
        }

        // Return the reversed integer
        return ans;
    }
}
