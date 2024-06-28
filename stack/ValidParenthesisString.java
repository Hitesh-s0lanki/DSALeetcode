import java.util.Stack;

public class ValidParenthesisString {
    public static boolean checkValidString(String s) {
        int n = s.length();
        int cnt = 0;
        Stack<Character> ch = new Stack<>();

        int i = 0;
        while (i < n) {
            char item = s.charAt(i);

            if (!ch.empty() && item == ')') {
                char peek = ch.peek();
                if (peek == '(') {
                    ch.pop();
                } else if (cnt > 0) {
                    cnt--;
                } else {
                    return false;
                }
            } else if (ch.empty() && item == ')') {
                return false;
            } else if (item == '(') {
                ch.push(item);
            } else {
                cnt++;
            }

            i++;
        }

        if (!ch.empty())
            return false;

        return true;
    }

    public static void main(String[] args) {
        System.out.println(checkValidString(")(*))"));
    }
}
