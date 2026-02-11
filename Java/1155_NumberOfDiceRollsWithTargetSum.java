class Solution1155 {
    public int numRollsToTarget(int n, int k, int target) {
        if (n == 1) {
            return target >= 1 && target <= k ? 1 : 0;
        }
        if (cache[n][target] != 0) {
            return cache[n][target];
        }
        int result = 0;
        for (int i = 1; i <= k; i++) {
            result += numRollsToTarget(n - 1, k, target - i);
            result %= MOD;
        }
        cache[n][target] = result;
        return result;
    }

    final private int MOD = 1_000_000_007;

    private int[][] cache = new int[31][1001];
}