import java.util.HashMap;
import java.util.Map;

class Solution1140 {
    public int stoneGameII(int[] piles) {
        init(piles);
        return dfs(0, 1);
    }

    private void init(int[] piles) {
        int n = piles.length;
        suffixSum = new int[n + 1];
        suffixSum[n] = 0;
        for (int i = n - 1; i >= 0; i--) {
            suffixSum[i] = suffixSum[i + 1] + piles[i];
        }
        this.piles = piles;
        cache = new HashMap<>();
    }

    private int dfs(int index, int M) {
        if (piles.length - index <= 2 * M) {
            return sumRemaining(index);
        }
        String key = index + "," + M;
        if (cache.containsKey(key)) {
            return cache.get(key);
        }
        int maxStones = 0;
        int sum = 0;
        for (int i = 1; i <= 2 * M; i++) {
            if (index + i - 1 < piles.length) {
                sum += piles[index + i - 1];
                int opponentStones = dfs(index + i, Math.max(M, i));
                maxStones = Math.max(maxStones, sum + (sumRemaining(index + i) - opponentStones));
            }
        }
        cache.put(key, maxStones);
        return maxStones;
    }

    private int sumRemaining(int start) {
        return suffixSum[start];
    }

    private int[] piles;
    private int[] suffixSum;
    private Map<String, Integer> cache;
}