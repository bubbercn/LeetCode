import java.util.Map;

class Solution1189 {
    public int maxNumberOfBalloons(String text) {
        int[] count = new int[26];
        for (char c : text.toCharArray()) {
            count[c - 'a']++;
        }
        int result = Integer.MAX_VALUE;
        for (Map.Entry<Character, Integer> entry : BALLOON_COUNT.entrySet()) {
            result = Math.min(result, count[entry.getKey() - 'a'] / entry.getValue());
        }
        return result;
    }

    private static final Map<Character, Integer> BALLOON_COUNT = Map.of(
        'b', 1,
        'a', 1,
        'l', 2,
        'o', 2,
        'n', 1
    );
}