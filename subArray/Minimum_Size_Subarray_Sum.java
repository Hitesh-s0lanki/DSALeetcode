public class Minimum_Size_Subarray_Sum {

    public static int solve(int target, int[] nums) {
        int n = nums.length;

        int sum = nums[0];

        int right = 0, left = 0;
        int minLen = Integer.MAX_VALUE;

        while (right < n) {

            while (left <= right && sum > target) {
                sum -= nums[left++];
            }

            if (sum == target) {
                minLen = Math.min(right - left + 1, minLen);
            }

            right++;
            if (right < n)
                sum += nums[right];
        }

        return minLen == Integer.MAX_VALUE ? 0 : minLen;
    }

    public static int minSubArrayLen(int target, int[] nums) {
        // check for total sum
        int sum = 0;
        for (int i : nums) {
            sum += i;
        }
        if (sum < target)
            return 0;

        while (solve(target, nums) == 0) {
            target++;
        }

        return solve(target, nums);
    }

    public static void main(String[] args) {
        int[] nums = { 1, 2, 3, 4, 5 };
        int k = 11;

        System.out.println(minSubArrayLen(k, nums));
    }
}
