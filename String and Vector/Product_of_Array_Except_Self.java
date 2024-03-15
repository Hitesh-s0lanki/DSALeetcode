public class Product_of_Array_Except_Self {
    public static int[] productExceptSelf(int[] nums) {
        int n = nums.length;

        int[] result = new int[n];
        // store prefix in result

        int prefixProduct = 1;
        for (int i = 0; i < n; i++) {
            result[i] = prefixProduct;
            prefixProduct *= nums[i];
        }

        // postfixProduct
        int postfixProduct = 1;
        for (int i = n - 1; i >= 0; i--) {
            result[i] *= postfixProduct;
            postfixProduct *= nums[i];
        }

        return result;
    }

    public static void main(String[] args) {
        int[] ans = productExceptSelf(new int[] { 1, 2, 3, 4 });

        for (int i : ans) {
            System.out.print(i + "\t");
        }
    }
}