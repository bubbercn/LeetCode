class Solution1140 {
    public int stoneGameII(int[] piles) {
        int n = piles.length;
        int[][] dp = new int[n][n + 1];
        int sum = 0;
        for (int i = n - 1; i >= 0; i--) {
            sum += piles[i];
            for (int j = n; j >= 1; j--) {
                int left = n - i;
                if (left <= j * 2) {
                    dp[i][j] = sum;
                    continue;
                }
                for (int x = 1; x <= j * 2; x++) {
                    if (i + x < n) {
                        dp[i][j] = Math.max(dp[i][j], sum - dp[i + x][Math.max(j, x)]);
                    }
                }
            }
        }
        return dp[0][1];
    }
}