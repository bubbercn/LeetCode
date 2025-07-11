import java.util.LinkedList;
import java.util.List;

class Solution1106 {
    public boolean parseBoolExpr(String expression) {
        List<Character> ops = new LinkedList<>();
        List<Boolean> values = new LinkedList<>();
        List<Boolean> begins = new LinkedList<>();
        boolean value = false;
        boolean temp = false;
        boolean begin = true;
        for (int i = 0; i < expression.length(); i++) {
            char c = expression.charAt(i);
            if (c == '!' || c == '&' || c == '|') {
                ops.add(c);
                values.add(value);
                value = false;
                begins.add(begin);
                begin = true;
            } else if (c == 't' || c == 'f') {
                if (begin) {
                    value = c == 't';
                } else {
                    temp = c == 't';
                }
            } else if (c == '(') {
                continue;
            } else if (c == ',') {
                if (!begin) {
                    if (ops.getLast() == '&') {
                        value = value && temp;
                    } else if (ops.getLast() == '|') {
                        value = value || temp;
                    }
                }
                begin = false;
            } else if (c == ')') {
                if (ops.getLast() == '!') {
                    value = !value;
                } else if (!begin) {
                    if (ops.getLast() == '&') {
                        value = value && temp;
                    } else if (ops.getLast() == '|') {
                        value = value || temp;
                    }
                }
                ops.removeLast();
                temp = value;
                value = values.removeLast();
                begin = begins.removeLast();
                if (begin) {
                    value = temp;
                }
            }
        }
        return value;
    }
}