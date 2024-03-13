import java.util.ArrayList;
import java.util.List;

class Solution {
    public List<List<Integer>> subsets = new ArrayList<>();

    public void createSubsets(int[] arr, int i, List<Integer> ans) {
        if (i >= arr.length) {
            subsets.add(ans);
            return;
        }

        // exclude
        createSubsets(arr, i + 1, ans);

        // include
        ans.add(arr[i]);
        createSubsets(arr, i + 1, ans);
    }

    public int sumSubarrayMins(int[] arr) {
        return 1;
    }
}

public class Sum_of_Subarray_Minimums {
    public static void main(String[] args) {
        int[] val = { 3, 1, 2, 4 };
        Solution s = new Solution();

        s.createSubsets(val, 0, new ArrayList<>());

        for (List<Integer> i : s.subsets) {
            for (int j : i) {
                System.out.print(j + " ");
            }
            System.out.println();
        }
    }
}