import java.util.ArrayList;
import java.util.List;

public class Majority_Element_II {
    public static List<Integer> majorityElement(int[] nums) {
        List<Integer> result = new ArrayList<Integer>();
        int n = nums.length;

        // Morre's algorithm
        // majority voting algorithm
        int cnt1 = 0, cnt2 = 0;
        int element1 = Integer.MAX_VALUE, element2 = Integer.MAX_VALUE;

        for (int i = 0; i < n; i++) {
            if (cnt1 == 0 && element2 != nums[i]) {
                cnt1 = 1;
                element1 = nums[i];
            } else if (cnt2 == 0 && element1 != nums[i]) {
                cnt2 = 1;
                element2 = nums[i];
            } else if (element1 == nums[i]) {
                cnt1++;
            } else if (element2 == nums[i]) {
                cnt2++;
            } else {
                cnt1--;
                cnt2--;
            }
        }

        // manual check
        cnt1 = 0;
        cnt2 = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] == element1)
                cnt1++;
            if (nums[i] == element2)
                cnt2++;
        }

        int mini = (int) (n / 3) + 1;

        if (cnt1 >= mini)
            result.add(element1);
        if (cnt2 >= mini)
            result.add(element2);

        return result;
    }

    public static void main(String[] args) {
        List<Integer> ans = majorityElement(new int[] { 3, 2, 3 });

        for (int i : ans) {
            System.out.print(i + "\t");
        }
    }
}
