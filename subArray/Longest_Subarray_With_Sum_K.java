// For Both Negative and positive

import java.util.HashMap;
import java.util.Map;

public class Longest_Subarray_With_Sum_K {
    public static int getLongestSubarray(int[] nums, int k) {
        int maxLen = 0;
        int sum = 0;

        Map<Integer, Integer> mapSum = new HashMap<>();

        for (int i = 0; i < nums.length; i++) {
            sum += nums[i];

            if (sum == k) {
                maxLen = Math.max(maxLen, i + 1);
            }

            if (mapSum.containsKey(sum - k)) {
                int len = i - mapSum.get(sum - k);
                maxLen = Math.max(maxLen, len);
            }

            if (!mapSum.containsKey(sum)) {
                mapSum.put(sum, i);
            }
        }

        return maxLen;
    }

    public static void main(String[] args) {
        int[] nums = { -1, 0, 1, 1, -1, -1, 0 };
        int k = 0;

        System.out.println(getLongestSubarray(nums, k));
    }
}