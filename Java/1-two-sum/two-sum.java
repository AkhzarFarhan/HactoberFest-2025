import java.util.HashMap;
import java.util.Map;

/**
 * Solution class for the Two Sum problem.
 * Given an array of integers and a target sum, find indices of two numbers that add up to the target.
 */
class Solution {
    
    /**
     * Finds indices of two numbers in the array that sum up to the target.
     *
     * @param arr    Input array of integers
     * @param target Target sum
     * @return Array containing indices of the two numbers, or empty array if no solution
     */
    public int[] twoSum(int[] arr, int target) {
        // Map to store each number and its index
        Map<Integer, Integer> map = new HashMap<>();

        // Traverse the array
        for (int i = 0; i < arr.length; i++) {
            int complement = target - arr[i]; // Number needed to reach the target

            // Check if complement exists in the map
            if (map.containsKey(complement)) {
                // Return indices of the complement and current element
                return new int[]{map.get(complement), i};
            }

            // Add current element and its index to the map
            map.put(arr[i], i);
        }

        // Return empty array if no pair sums to target
        return new int[]{};
    }

    // Optional: Main method to test the solution
    public static void main(String[] args) {
        Solution sol = new Solution();
        int[] arr = {2, 7, 11, 15};
        int target = 9;

        int[] result = sol.twoSum(arr, target);
        if (result.length == 2) {
            System.out.println("Indices: " + result[0] + ", " + result[1]);
            System.out.println("Numbers: " + arr[result[0]] + ", " + arr[result[1]]);
        } else {
            System.out.println("No solution found!");
        }
    }
}
