import java.util.Arrays;
import java.util.HashMap;
import java.util.Map;

class Solution1048 {
    public int longestStrChain(String[] words) {
        Arrays.sort(words, (a, b) -> a.length() - b.length());
        Map<String, Integer> map = new HashMap<>();
        int result = 0;
        for (String word : words) {
            if (map.isEmpty()) {
                map.put(word, 1);
                result = 1;
            } else {
                int max = 1;
                for (int i = 0; i < word.length(); i++) {
                    String temp = word.substring(0, i) + word.substring(i + 1);
                    max = Math.max(max, map.getOrDefault(temp, 0) + 1);
                }
                map.put(word, max);
                result = Math.max(result, max);
            }
        }
        return result;
    }
}