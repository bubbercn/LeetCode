import java.util.HashMap;
import java.util.Map;

class Solution1025 {
    public boolean divisorGame(int n) {
        if (n == 1)
            return false;

        if (cache.get(n) != null)
            return cache.get(n);

        for (int i = 1; i < n; i++) {
            if (n % i == 0 && !divisorGame(n - i)) {
                cache.put(n, true);
                return true;
            }
        }
        cache.put(n, false);
        return false;
    }

    private static final Map<Integer, Boolean> cache = new HashMap<>();
}