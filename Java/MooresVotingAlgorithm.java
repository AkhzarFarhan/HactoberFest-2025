import java.util.Scanner;

public class MooresVotingAlgorithm {

    // Function to find the majority element
    public static int findMajorityElement(int[] nums) {
        if (nums.length == 0) return -1; // Handle empty array case
        if (nums.length == 1) return nums[0]; // Single element is the majority
        
        int candidate = findCandidate(nums);  // Find potential candidate
        return isMajority(nums, candidate) ? candidate : -1;  // Verify majority
    }

    // Function to find the candidate for majority element
    private static int findCandidate(int[] nums) {
        int count = 0, candidate = -1;
        for (int num : nums) {
            if (count == 0) {
                candidate = num;  // New candidate
            }
            count += (num == candidate) ? 1 : -1;  // Adjust count
        }
        return candidate;
    }

    // Function to check if the candidate is actually the majority element
    private static boolean isMajority(int[] nums, int candidate) {
        int count = 0;
        for (int num : nums) {
            if (num == candidate) count++;
        }
        return count > nums.length / 2;  // Check if candidate appears more than n/2 times
    }

    // Main method to test the algorithm
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        System.out.print("Enter the number of elements in the array: ");
        int n = scanner.nextInt();
        
        // Input validation: Must have at least 1 element
        if (n <= 0) {
            System.out.println("Array size must be greater than 0.");
            return;
        }

        int[] nums = new int[n];
        System.out.println("Enter the elements of the array:");
        for (int i = 0; i < n; i++) {
            nums[i] = scanner.nextInt();
        }

        int majorityElement = findMajorityElement(nums);
        if (majorityElement != -1) {
            System.out.println("The majority element is: " + majorityElement);
        } else {
            System.out.println("There is no majority element.");
        }
    }
}
