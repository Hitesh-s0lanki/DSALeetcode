public class MaximumProductSubarray {
    public static int maxProduct(int[] nums) {

        int n = nums.length;
        int maxi = Integer.MIN_VALUE;

        int prefix = 1, suffix = 1;
        for (int i = 0; i < n; i++) {
            if (prefix == 0)
                prefix = 1;
            if (suffix == 0)
                suffix = 1;

            prefix = prefix * nums[i];
            suffix = suffix * nums[n - i - 1];

            maxi = Math.max(maxi, Math.max(prefix, suffix));
        }
        return maxi;
    }

    public static void main(String[] args) {
        System.out.println(maxProduct(new int[] { 2, 3, -2, 4 }));
    }
}
