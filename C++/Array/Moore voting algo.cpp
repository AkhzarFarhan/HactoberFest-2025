public class MajorityElement {
    public static int findMajorityElement(int[] nums) {
        // Phase 1: Find a candidate for majority element
        int candidate = nums[0];
        int count = 1;

        for (int i = 1; i < nums.length; i++) {
            if (nums[i] == candidate) {
                count++;
            } else {
                count--;
            }
            if (count == 0) {
                candidate = nums[i];
                count = 1;
            }
        }

        // Phase 2: Verify the candidate
        count = 0;
        for (int num : nums) {
            if (num == candidate) {
                count++;
            }
        }

        // Return the candidate if it is the majority element
        if (count > nums.length / 2) {
            return candidate;
        } else {
            throw new IllegalArgumentException("No majority element found");
        }
    }

    public static void main(String[] args) {
        int[] nums = {2, 2, 1, 1, 2, 2, 2};
        try {
            System.out.println("Majority Element: " + findMajorityElement(nums));
        } catch (IllegalArgumentException e) {
            System.out.println(e.getMessage());
        }
    }
}
