class Solution1049 {
    public int lastStoneWeightII(int[] stones) {
        int sum = 0;
        for (int stone : stones) {
            sum += stone;
        }
        int n = stones.length;
        int m = sum / 2;
        int[] dp = new int[m + 1];
        for (int i = 1; i <= n; i++) {
            for (int j = m; j >= stones[i - 1]; j--) {
                dp[j] = Math.max(dp[j], dp[j - stones[i - 1]] + stones[i - 1]);
            }
        }
        return sum - 2 * dp[m];
    }
}