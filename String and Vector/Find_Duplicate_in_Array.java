import java.util.ArrayList;
import java.util.Arrays;

class Solution {
    public static int findDuplicate(ArrayList<Integer> arr, int n) {

        int ans = 0;

        for (int i = 0; i < arr.size() - 1; i++) {
            ans = arr.get(i);
            for (int j = i + 1; j < arr.size(); j++) {
                if ((ans ^ arr.get(j)) == 0)
                    return arr.get(i);
            }
        }

        return ans;
    }
}

public class Find_Duplicate_in_Array {
    public static void main(String[] args) {
        ArrayList<Integer> arr = new ArrayList<>(Arrays.asList(1, 3, 4, 2, 2));

        System.out.println(Solution.findDuplicate(arr, arr.size()));
    }
}