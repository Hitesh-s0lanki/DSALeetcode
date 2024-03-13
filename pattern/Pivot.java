public class Pivot {
    public static int pivotInteger(int n) {

        int ans = -1;
        for (int i = 1; i <= n; i++) {
            long left_sum = (i * (i + 1)) / 2;
            long right_sum = (n * (n + 1)) / 2 - (i * (i + 1)) / 2 + i;

            if (right_sum == left_sum) {
                ans = i;
            }
        }

        return ans;
    }

    public static void main(String[] args) {
        System.out.println(pivotInteger(8));
    }
}