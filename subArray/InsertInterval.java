import java.util.*;

public class InsertInterval {
    public static int[][] insert(int[][] intervals, int[] newInterval) {
        List<int[]> ans = new ArrayList<>();
        int start = newInterval[0], end = newInterval[1];
        boolean inserted = false;

        for (int[] inv : intervals) {
            int cstart = inv[0], cend = inv[1];

            if (cend < start || inserted) {
                ans.add(new int[] { cstart, cend });
                continue;
            }

            start = Math.min(start, cstart);
            if (end < cstart) {
                ans.add(new int[] { start, end });
                ans.add(new int[] { cstart, cend });
                inserted = true;
                continue;
            }

            if (end <= cend) {
                ans.add(new int[] { start, cend });
                inserted = true;
            }
        }

        if (!inserted) {
            ans.add(new int[] { start, end });
        }

        return ans.toArray(new int[ans.size()][]);
    }

    public static void main(String[] args) {
        int[][] ans = insert(new int[][] { { 1, 2 }, { 3, 5 }, { 6, 7 }, { 8, 10 }, { 12, 16 } }, new int[] { 4, 8 });

        // int[][] ans = insert(new int[][] { { 1, 3 }, { 6, 9 } }, new int[] { 2, 5 });

        for (int[] i : ans) {
            System.err.print("[");
            System.out.print(i[0] + ", " + i[1]);
            System.out.print("],");
        }
    }
}
