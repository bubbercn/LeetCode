import java.util.List;
import java.util.ArrayList;
import java.util.Set;
import java.util.HashSet;
import java.util.LinkedList;

class Solution1096 {
    public List<String> braceExpansionII(String expression) {
        Set<String> set = helper1(expression);
        List<String> result = new ArrayList<>(set);
        result.sort(null);
        return result;
    }

    private Set<String> helper1(String s) {
        Set<String> result = new HashSet<>();
        int begin = -1;
        for (int i = 0; i < s.length(); i++) {
            char c = s.charAt(i);
            if (c == '{') {
                if (begin != -1) {
                    String sub = s.substring(begin, i);
                    if (result.isEmpty()) {
                        result.add(sub);
                    } else {
                        Set<String> newResult = new HashSet<>();
                        for (String str1 : result) {
                            newResult.add(str1 + sub);
                        }
                        result = newResult;
                    }
                }
                begin = -1;
                int x = getMatch(s, i);
                Set<String> temp = helper2(s.substring(i + 1, x));
                Set<String> newResult = new HashSet<>();
                if (result.isEmpty()) {
                    result.addAll(temp);
                } else {
                    for (String str1 : result) {
                        for (String str2 : temp) {
                            newResult.add(str1 + str2);
                        }
                    }
                    result = newResult;
                }
                i = x;
            } else {
                if (begin == -1) {
                    begin = i;
                }
            }
        }
        if (begin != -1) {
            String sub = s.substring(begin);
            if (result.isEmpty()) {
                result.add(sub);
            } else {
                Set<String> newResult = new HashSet<>();
                for (String str1 : result) {
                    newResult.add(str1 + sub);
                }
                result = newResult;
            }
        }
        return result;
    }

    private int getMatch(String s, int i) {
        LinkedList<Character> stack = new LinkedList<>();
        stack.push('{');
        for (int j = i + 1; j < s.length(); j++) {
            char c = s.charAt(j);
            if (c == '{') {
                stack.push(c);
            } else if (c == '}') {
                stack.pop();
                if (stack.isEmpty()) {
                    return j;
                }
            }
        }
        return -1;
    }

    private Set<String> helper2(String s) {
        Set<String> result = new HashSet<>();
        LinkedList<String> stack = new LinkedList<>();
        int begin = 0;
        for (int i = 0; i < s.length(); i++) {
            char c = s.charAt(i);
            if (c == ',') {
                if (stack.isEmpty()) {
                    Set<String> temp = helper1(s.substring(begin, i));
                    result.addAll(temp);
                    begin = i + 1;
                }
            } else if (c == '{') {
                stack.push("{");
            } else if (c == '}') {
                stack.pop();
            }
        }
        Set<String> temp = helper1(s.substring(begin));
        result.addAll(temp);
        return result;
    }
}