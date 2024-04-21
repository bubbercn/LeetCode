class Solution1043 {
    public int maxSumAfterPartitioning(int[] arr, int k) {
        int n = arr.length;
        int[] dp = new int[n];
        dp[0] = arr[0];
        for (int i = 1; i < n; i++) {
            int max = arr[i];
            dp[i] = dp[i - 1] + max;
            for (int j = 1; j < k; j++)
            {
                if (i - j >= 0)
                {
                    max = Math.max(max, arr[i - j]);
                    dp[i] = Math.max(dp[i], (i - j - 1 >= 0 ? dp[i - j - 1] : 0) + max * (j + 1));
                }
            }
        }
        return dp[n - 1];
    }
}