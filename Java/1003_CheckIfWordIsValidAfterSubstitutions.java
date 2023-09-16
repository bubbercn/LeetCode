class Solution1003 {
    public boolean isValid(String s) {
        StringBuffer sb = new StringBuffer(s);
        for (int i = 0; i < sb.length(); i++) {
            if (sb.charAt(i) == 'c') {
                if (i < 2)
                    return false;
                if (sb.charAt(i - 1) != 'b' || sb.charAt(i - 2) != 'a')
                    return false;
                sb.replace(i - 2, i + 1, "");
                i -= 3;
            }
        }
        return sb.isEmpty();
    }
}