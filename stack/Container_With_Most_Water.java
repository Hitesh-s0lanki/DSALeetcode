class Solution {

    public int maxArea(int[] height) {

        int ans = 0;

        int i = 0;
        int j = height.length - 1;

        while (i < j) {
            if (height[i] > height[j]) {
                ans = Math.max(ans, (j - i) * height[j]);
                j--;
            } else {
                ans = Math.max(ans, (j - i) * height[i]);
                i++;
            }
        }

        return ans;
    }
}

public class Container_With_Most_Water {
    public static void main(String[] args) {

        int[] val = { 10, 9, 8, 7, 6, 5, 4, 3, 2, 1 };

        Solution s = new Solution();

        System.out.println(s.maxArea(val));
    }
}
