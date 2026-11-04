class Solution1163 {
    public String lastSubstring(String s) {
        int left = 0;
        int right = 1;
        int step = 0;

        while (right + step < s.length()) {
            if (s.charAt(left + step) == s.charAt(right + step)) {
                step++;
            } else if (s.charAt(left + step) > s.charAt(right + step)) {
                right = right + step + 1;
                step = 0;
            } else {
                left = Math.max(left + step + 1, right);
                right = left + 1;
                step = 0;
            }
        }

        return s.substring(left);
    }
}