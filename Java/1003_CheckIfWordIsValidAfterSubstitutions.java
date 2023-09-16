import java.util.Stack;

class Solution1003 {
    public boolean isValid(String s) {
        Stack<Character> stack = new Stack<>();
        for (int i = 0; i < s.length(); i++) {
            if (s.charAt(i) != 'c') {
                stack.push(s.charAt(i));
            } else {
                if (stack.isEmpty() || stack.pop() != 'b') {
                    return false;
                }
                if (stack.isEmpty() || stack.pop() != 'a') {
                    return false;
                }
            }
        }
        return stack.isEmpty();
    }
}