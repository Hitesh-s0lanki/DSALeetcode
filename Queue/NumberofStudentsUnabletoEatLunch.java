import java.util.LinkedList;
import java.util.Queue;

public class NumberofStudentsUnabletoEatLunch {
    public static int countStudents(int[] students, int[] sandwiches) {

        int ans = 0;
        Queue<Integer> q = new LinkedList<>();

        // add Student to Queue
        for (int student : students) {
            q.add(student);
        }

        for (int i = 0; i < sandwiches.length; i++) {
            int n = q.size();

            while (sandwiches[i] != q.peek()) {

                if (ans == n) {
                    return n;
                }

                int val = q.peek();
                q.poll();
                ans++;
                q.add(val);
            }
            ans = 0;
            q.poll();
        }

        return 0;
    }

    public static void main(String[] args) {
        System.out.println(countStudents(new int[] { 1, 1, 0, 0 }, new int[] { 0, 1, 0, 1 }));
    }
}