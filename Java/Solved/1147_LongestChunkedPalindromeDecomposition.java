class Solution1147 {
    public int longestDecomposition(String text) {
        return helper(text, 0, text.length() - 1);
    }

    private int helper(String text, int left, int right) {
        if (left > right) {
            return 0;
        }
        for (int len = 1; left + len - 1 < right - len + 1; len++) {
            String leftSub = text.substring(left, left + len);
            String rightSub = text.substring(right - len + 1, right + 1);
            if (leftSub.equals(rightSub)) {
                return 2 + helper(text, left + len, right - len);
            }
        }
        return 1;
    }
}