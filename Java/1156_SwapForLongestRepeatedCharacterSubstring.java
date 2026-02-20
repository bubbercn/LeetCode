import java.util.Map;
import java.util.TreeMap;

class Solution1156 {
    public int maxRepOpt1(String text) {
        Map<Integer, Integer>[] charCount = new Map[26];
        for (int i = 0; i < 26; i++) {
            charCount[i] = new TreeMap<>();
        }
        {
            int start = 0;
            for (int i = 1; i < text.length(); i++) {
                if (text.charAt(i) != text.charAt(start)) {
                    charCount[text.charAt(start) - 'a'].put(start, i);
                    start = i;
                }
            }
            charCount[text.charAt(start) - 'a'].put(start, text.length());
        }
        int max = 0;
        for (int i = 0; i < 26; i++) {
            int prevStart = -1;
            int prevEnd = -1;
            for (var it = charCount[i].entrySet().iterator(); it.hasNext();) {
                var entry = it.next();
                int start = entry.getKey();
                int end = entry.getValue();
                if (prevStart != -1) {
                    if (prevEnd + 1 == start) {
                        if (charCount[i].size() > 2) {
                            max = Math.max(max, end - prevStart);
                        } else {
                            max = Math.max(max, end - prevStart - 1);
                        }
                    }
                }
                if (charCount[i].size() > 1) {
                    max = Math.max(max, end - start + 1);
                } else {
                    max = Math.max(max, end - start);
                }
                prevStart = start;
                prevEnd = end;
            }
        }
        return max;
    }
}