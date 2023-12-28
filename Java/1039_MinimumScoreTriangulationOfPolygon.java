import java.util.HashMap;
import java.util.Map;

class Solution1039 {
    public int minScoreTriangulation(int[] values) {
        return helper(values, 0, values.length - 1);
    }

    private int helper(int[] values, int start, int end) {
        if (start + 1 >= end) {
            return 0;
        }
        int key = start * values.length + end;
        if (cache.containsKey(key)) {
            return cache.get(key);
        }
        int result = Integer.MAX_VALUE;
        for (int i = start + 1; i < end; i++) {
            result = Math.min(result,
                    helper(values, start, i) + helper(values, i, end) + values[start] * values[i ] * values[end]);
        }
        cache.put(key, result);
        return result;
    }

    private Map<Integer, Integer> cache = new HashMap<>();
}