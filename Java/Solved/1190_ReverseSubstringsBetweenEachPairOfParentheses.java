class Solution1190 {
    public String reverseParentheses(String s) {
        for (int i = 0; i < s.length(); i++) {
            if (s.charAt(i) == '(') {
                int j = i;
                int start = 0;
                int end = 0;
                while (j < s.length()) {
                    if (s.charAt(j) == '(') {
                        start = j; // mark the position of the last '('
                    } else if (s.charAt(j) == ')') {
                        end = j; // mark the position of the matching ')'
                        break;
                    }
                    j++;
                }
                String reversed = new StringBuilder(s.substring(start + 1, end)).reverse().toString();
                s = s.substring(0, start) + reversed + s.substring(end + 1);
                i--;
            }
        }
        return s;
    }
}