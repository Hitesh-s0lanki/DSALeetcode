public class Positive_Longest_Subarray_With_Sum_K {
    public static int longestSubarrayWithSumK(int[] a, long k) {
        int maxLen = 0;
        long sum = a[0];

        int left = 0;
        int right = 0;

        int n = a.length;

        while (right < n) {

            while (left <= right && sum > k) {
                sum -= a[left++];
            }
            if (sum == k) {
                maxLen = Math.max(maxLen, right - left + 1);
            }

            right++;
            if (right < n)
                sum += a[right];
        }

        return maxLen;
    }

    public static void main(String[] args) {
        int[] nums = { -1, 0, 1, 1, -1, -1, 0 };
        int k = 0;

        System.out.println(longestSubarrayWithSumK(nums, k));
    }
}
