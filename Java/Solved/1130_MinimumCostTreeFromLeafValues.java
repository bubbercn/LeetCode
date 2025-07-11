import java.util.HashMap;
import java.util.Map;

class Solution1130 {
    public int mctFromLeafValues(int[] arr) {
        return mctFromLeafValues(arr, 0, arr.length - 1);
    }

    private int mctFromLeafValues(int[] arr, int left, int right) {
        if (left == right) {
            return arr[left];
        }

        Integer temp = getCache(left, right);
        if (temp != null) {
            return temp;
        }
        
        int result = Integer.MAX_VALUE;
        for (int i = left; i < right; i++) {
            int cost = getMax(arr, left, i) * getMax(arr, i + 1, right);
            result = Math.min(result, cost + (left == i ? 0 : mctFromLeafValues(arr, left, i)) + 
                                 (i + 1 == right ? 0 : mctFromLeafValues(arr, i + 1, right)));
        }

        setCache(left, right, result);
        return result;
    }
    

    private final Map<String, Integer> cache = new HashMap<>();
    private final Map<String, Integer> maxCache = new HashMap<>();

    private Integer getCache(int left, int right) {
        return cache.get(left + "," + right);
    }
    private void setCache(int left, int right, int value) {
        cache.put(left + "," + right, value);
    }

    private int getMax(int[] arr, int left, int right) {
        String key = left + "," + right;
        if (maxCache.containsKey(key)) {
            return maxCache.get(key);
        }
        int max = Integer.MIN_VALUE;
        for (int i = left; i <= right; i++) {
            max = Math.max(max, arr[i]);
        }
        maxCache.put(key, max);
        return max;
    }
}