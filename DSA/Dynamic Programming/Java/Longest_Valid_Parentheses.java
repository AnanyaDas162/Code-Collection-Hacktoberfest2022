import java.util.Stack;
//https://leetcode.com/problems/longest-valid-parentheses/
//https://practice.geeksforgeeks.org/problems/longest-valid-parentheses5657/1
//https://www.youtube.com/watch?v=8CYhffMML8o
public class Longest_Valid_Parentheses {
    static int maxLength(String s) {
        int maxans = 0;
        Stack<Integer> stack = new Stack<>();
        stack.push(-1);
        for (int i = 0; i < s.length(); i++) {
            if (s.charAt(i) == '(') {
                stack.push(i);
            } else {
                stack.pop();
                if (stack.empty()) {
                    stack.push(i);
                } else {
                    maxans = Math.max(maxans, i - stack.peek());
                }
            }
        }
        return maxans;
    }

    public static void main(String[] args) {

    }
}
