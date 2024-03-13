import java.util.Stack;

class Solution {
    public int[] prevNumberOfElement(int[] h, int n) {

        int[] ans = new int[n];
        Stack<Integer> stack = new Stack<>();
        stack.push(-1);

        for (int i = 0; i < n; i++) {
            int curr = h[i];
            while (stack.peek() != -1 && h[stack.peek()] >= curr) {
                stack.pop();
            }
            ans[i] = stack.peek();
            stack.push(i);
        }

        return ans;
    }

    // {1, 3, 4, 2}
    public int[] nextNumberOfElement(int[] h, int n) {

        int[] ans = new int[n];
        Stack<Integer> stack = new Stack<>();
        stack.push(-1);

        for (int i = n - 1; i >= 0; i--) {
            int curr = h[i];
            while (stack.peek() != -1 && h[stack.peek()] >= curr) {
                stack.pop();
            }
            ans[i] = stack.peek();
            stack.push(i);
        }
        return ans;
    }

    public int largestRectangleArea(int[] heights) {

        int n = heights.length;

        int[] leftSide = prevNumberOfElement(heights, n);
        int[] rightSide = nextNumberOfElement(heights, n);

        int maxArea = 0;
        int i = 0;
        while (i < n) {
            int length = heights[i];
            if (rightSide[i] == -1) {
                rightSide[i] = n;
            }
            int breath = rightSide[i] - leftSide[i] - 1;

            maxArea = Math.max(maxArea, length * breath);
            i++;
        }
        return maxArea;
    }
}

public class histogram {
    public static void main(String[] args) {
        Solution s = new Solution();

        int val[] = { 1, 3, 4, 2 };

        int[] prev = s.prevNumberOfElement(val, val.length);
        int[] next = s.nextNumberOfElement(val, val.length);

        for (Integer i : prev) {
            System.out.print(i + "\t");
        }
        System.out.println();
        for (Integer i : next) {
            System.out.print(i + "\t");
        }
    }
}