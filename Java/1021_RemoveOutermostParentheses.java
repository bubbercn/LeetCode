class Solution1021 {
    public String removeOuterParentheses(String s) {
        StringBuilder builder = new StringBuilder();
        int count = 0;
        for (int i = 0; i < s.length(); i++) {
            char curr = s.charAt(i);
            if (curr == '(') {
                if (count++ == 0)
                    continue;
            } else {
                if (--count == 0)
                    continue;
            }
            builder.append(curr);
        }
        return builder.toString();
    }
}