class Solution1155 {
    public int numRollsToTarget(int n, int k, int target) {
        final int MOD = 1_000_000_007;
        
        // dp[sum] = number of ways to reach this sum
        int[] dp = new int[target + 1];
        dp[0] = 1; // base case: one way to get sum 0 with 0 dice
        
        // For each die
        for (int die = 1; die <= n; die++) {
            int[] newDp = new int[target + 1];
            // For each possible sum we can currently reach
            for (int sum = 0; sum <= target; sum++) {
                if (dp[sum] > 0) {
                    // Try each face value on this die
                    for (int face = 1; face <= k; face++) {
                        int newSum = sum + face;
                        if (newSum <= target) {
                            newDp[newSum] = (newDp[newSum] + dp[sum]) % MOD;
                        }
                    }
                }
            }
            dp = newDp;
        }
        
        return dp[target];
    }
}