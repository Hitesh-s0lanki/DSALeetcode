import java.util.Stack;

public class MinimumRemovetoMakeValidParentheses {
    public static String minRemoveToMakeValid(String s) {

        Stack<Character> ch = new Stack<>();
        int cnt = 0;
        StringBuilder result = new StringBuilder();

        for (int i = 0; i < s.length(); i++) {
            if (s.charAt(i) == '(') {
                cnt++;
            } else if (s.charAt(i) == ')') {
                cnt--;
            }

            if (s.charAt(i) == ')' && cnt < 0) {
                cnt = 0;
            } else {
                ch.push(s.charAt(i));
            }
        }

        cnt = 0;

        while (!ch.empty()) {
            char item = ch.peek();
            ch.pop();

            if (item == '(' && cnt <= 0) {
                continue;
            } else if (item == ')') {
                cnt++;
            } else if (item == '(') {
                cnt--;
            }

            result.append(item);
        }

        return result.reverse().toString();
    }

    public static void main(String[] args) {
        System.out.println(minRemoveToMakeValid("lee(t(c)o)de)"));
        System.out.println(minRemoveToMakeValid("))(("));
        System.out.println(minRemoveToMakeValid("())()((("));
    }
}
