import java.util.HashMap;
import java.util.Map;

class Solution {
    public int[] twoSum(int[] arr, int target) {
        // Create a HashMap to store array elements and their indices
        // Key = array element, Value = index
        Map<Integer, Integer> map = new HashMap<>();

        // Loop through each element of the array
        for (int i = 0; i < arr.length; i++) {
            // Calculate the number we need to reach the target
            int more = target - arr[i];

            // Check if the required number is already in the map
            // If yes, we found the pair → return their indices
            if (map.containsKey(more)) {
                // map.get(more) gives index of the first number
                // i is the index of the current number
                return new int[] { map.get(more), i };
            }

            // If not found, add the current element and its index to the map
            map.put(arr[i], i);
        }

        // If no pair is found, return an empty array
        return new int[] {};
    }
}
