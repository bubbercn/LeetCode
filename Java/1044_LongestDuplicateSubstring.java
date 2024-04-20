import java.util.HashSet;
import java.util.Set;

class Solution1044 {
    public String longestDupSubstring(String s) {
        int n = s.length();
        int min = 0;
        int max = n;
        String result = "";
        while (min < max) {
            int mid = min + (max - min) / 2;
            String temp = search(mid, s);
            if (temp != null) {
                result = temp;
                min = mid + 1;
            } else {
                max = mid;
            }
        }
        return result;
    }

    private String search(int len, String s) {
        int n = s.length();
        long hash = 0;
        long base = 29;
        long baseLen = 1;
        for (int i = 0; i < len; i++) {
            hash = (hash * base + s.charAt(i) - 'a');
            baseLen *= base;
        }
        Set<Long> set = new HashSet<>();
        set.add(hash);
        for (int i = 1; i < n - len + 1; i++) {
            hash = hash * base + s.charAt(i + len - 1) - 'a' - (s.charAt(i - 1) - 'a') * baseLen;;
            if (set.contains(hash)) {
                return s.substring(i, i + len);
            }
            set.add(hash);
        }
        return null;
    }
}