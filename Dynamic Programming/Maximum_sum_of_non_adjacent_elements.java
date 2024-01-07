import java.util.ArrayList;
import java.util.Arrays;

public class Maximum_sum_of_non_adjacent_elements {
    public static int maximumNonAdjacentSum(ArrayList<Integer> nums) {

        // Solving using dp
        int prev1 = nums.get(0);
        int prev2 = 0;

        for (int i = 1; i < nums.size(); i++) {
            int incl = nums.get(i) + prev2;
            int excl = prev1;

            int ans = Math.max(incl, excl);
            prev2 = prev1;
            prev1 = ans;
        }

        return prev1;
    }

    public static void main(String[] args) {
        ArrayList<Integer> nums = new ArrayList<Integer>(Arrays.asList(2, 1, 4, 9));

        System.out.println(maximumNonAdjacentSum(nums));
    }
}