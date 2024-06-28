import java.util.*;

public class ContiguousArray {
    public static int findMaxLength(int[] nums) {
        int maxLen = 0;
        int sum = 0;

        Map<Integer, Integer> mapSum = new HashMap<>();

        for (int i = 0; i < nums.length; i++) {

            sum += (nums[i] == 0) ? -1 : 1;

            if (sum == 0) {
                maxLen = Math.max(maxLen, i + 1);
            }

            if (mapSum.containsKey(sum)) {
                maxLen = Math.max(maxLen, i - mapSum.get(sum));
            } else {
                mapSum.put(sum, i);
            }
        }

        return maxLen;
    }

    public static void main(String[] args) {
        System.out.println(findMaxLength(new int[] { 0, 1, 0 }));
    }
}
