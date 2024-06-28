import java.util.ArrayList;
import java.util.List;

public class Pascal_Traingle {

    public static long getSingleValue(int row, int col) {
        return Combination.nCr(row - 1, col - 1);
    }

    public static int[] generateRow(int n) {
        int[] result = new int[n];

        int val = 1;
        result[0] = val;

        for (int i = 1; i < n; i++) {
            val = val * (n - i);
            val = val / i;
            result[i] = val;
        }

        return result;
    }

    public static int[][] pascalTriangle(int N) {
        int[][] result = new int[N][N];

        for (int i = 0; i < N; i++) {
            result[i] = generateRow(i + 1);
        }

        return result;
    }

    public List<Integer> generateRowList(int n) {
        List<Integer> result = new ArrayList<>(n);

        int val = 1;
        result.add(val);

        for (int i = 1; i < n; i++) {
            val = val * (n - i);
            val = val / i;
            result.add(val);
        }

        return result;
    }

    public List<List<Integer>> generate(int numRows) {
        List<List<Integer>> result = new ArrayList<>();

        for (int i = 1; i < numRows; i++) {
            result.add(generateRowList(i));
        }

        return result;
    }

    public static void main(String[] args) {
        int[][] ans = pascalTriangle(4);

        for (int[] i : ans) {
            for (int j : i) {
                System.out.print(j + "\t");
            }
            System.out.println();
        }
    }
}
