import java.util.Arrays;

class Solution1027 {
    public int longestArithSeqLength(int[] nums) {
        int n = nums.length;
        int[][] dp = new int[n][1001];
        for (int i = 0; i < n; i++) {
            Arrays.fill(dp[i], 1);
        }
        int result = 0;
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                int d = nums[i] - nums[j] + 500;
                dp[i][d] = Math.max(dp[i][d], dp[j][d] + 1);
                result = Math.max(result, dp[i][d]);
            }
        }
        return result;
    }
}