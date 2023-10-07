import java.util.HashSet;
import java.util.Set;

class Solution1016 {
    public boolean queryString(String s, int n) {
        Set<Integer> values = new HashSet<Integer>();
        for (int i = 0; i < s.length(); i++) {
            if (s.charAt(i) == '0') {
                continue;
            }
            int value = 0;
            for (int j = i; j < s.length(); j++) {
                value = (value << 1) + (s.charAt(j) - '0');
                if (value > n)
                    break;
                values.add(value);
            }
        }
        return values.size() == n;
    }
}