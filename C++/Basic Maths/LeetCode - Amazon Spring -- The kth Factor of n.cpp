class Solution {
    public static int kthFactor(int n, int k) {
    int count = 0;

        // Loop from 1 to sqrt(n) to find factors
        for (int i = 1; i <= Math.sqrt(n); i++) {
            if (n % i == 0) {
                count++; // Count the factor
                if (count == k) {
                    return i; // Return the k-th factor if found
                }
            }
        }

        // Check factors greater than sqrt(n)
        for (int i = (int) Math.sqrt(n); i >= 1; i--) {
            if (n % i == 0) {
                int factor = n / i; // Paired factor
                if (factor != i) { // Avoid counting sqrt(n) twice if n is a perfect square
                    count++;
                    if (count == k) {
                        return factor;
                    }
                }
            }
        }
        
        return -1; 
    }
}

