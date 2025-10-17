class Solution {
    public int maxArea(int[] height) {
        // Length of the array
        int n = height.length;

        // Initialize two pointers: left (lp) and right (rp)
        int lp = 0, rp = n - 1;

        // Variable to store the maximum water area
        int maxWater = 0;

        // Loop until the two pointers meet
        while (lp < rp) {
            // Width between the two lines
            int w = rp - lp;

            // Height is determined by the shorter line
            int ht = Math.min(height[lp], height[rp]);

            // Calculate the current area of water container
            int currWater = w * ht;

            // Update maximum water area if current area is greater
            maxWater = Math.max(maxWater, currWater);

            // Move the pointer pointing to the shorter line
            // Because increasing the shorter line might give a larger area
            if (height[lp] < height[rp]) {
                lp++;   // move left pointer to the right
            } else {
                rp--;   // move right pointer to the left
            }
        }

        // Return the maximum water area found
        return maxWater;
    }
}
