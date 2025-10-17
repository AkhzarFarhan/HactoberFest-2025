import java.util.Scanner;

public class MooreVoting {

    public static int findCandidate(int[] nums) {
        int count = 0, candidate = -1;

        for (int num : nums) {
            if (count == 0) {
                candidate = num;
                count = 1;
            } else if (num == candidate) {
                count++;
            } else {
                count--;
            }
        }

        return candidate;
    }

    public static boolean isMajority(int[] nums, int candidate) {
        int count = 0;
        for (int num : nums) {
            if (num == candidate) {
                count++;
            }
        }
        return count > nums.length / 2;
    }

    public static void printMajority(int[] nums) {
        int candidate = findCandidate(nums);

        if (isMajority(nums, candidate)) {
            System.out.println("Majority element is: " + candidate);
        } else {
            System.out.println("No majority element found.");
        }
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter the number of elements: ");
        int n = scanner.nextInt();

        int[] nums = new int[n];

        System.out.println("Enter the elements of the array:");
        for (int i = 0; i < n; i++) {
            nums[i] = scanner.nextInt();
        }
        printMajority(nums);

        scanner.close();
    }
}