import java.util.HashMap;
import java.util.Map;

public class Binary_Subarrays_With_Sum {
    public static int numSubarraysWithSum(int[] nums, int goal) {

        Map<Integer, Integer> count = new HashMap<>();

        int current_sum = 0;
        int subarray_count = 0;
        count.put(0, 1);

        for (int i = 0; i < nums.length; i++) {
            current_sum += nums[i];

            if (count.containsKey(current_sum - goal)) {
                subarray_count += count.get(current_sum - goal);
            }

            if (!count.containsKey(current_sum)) {
                count.put(current_sum, 0);
            }

            count.put(current_sum, count.get(current_sum) + 1);
        }

        return subarray_count;

    }

    public static void main(String[] args) {
        System.out.println(numSubarraysWithSum(new int[] { 1, 2, 3, -3, 1, 1, 1, 4, 2, -3 }, 3));
    }
}