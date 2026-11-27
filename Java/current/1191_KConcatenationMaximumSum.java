class Solution1191 {
    public int kConcatenationMaxSum(int[] arr, int k) {
        if (k == 1)
            return (int) hConcatenationMaxSum(arr, 1);

        long sum = 0;
        for (int num : arr) {
            sum += num;
        }
        sum %= MOD;

        if (sum > 0) {
            long result = hConcatenationMaxSum(arr, 2);
            result += (k - 2) * sum;
            return (int) (result % MOD);
        } else
            return (int) hConcatenationMaxSum(arr, 2);
    }

    private long hConcatenationMaxSum(int[] arr, int k) {
        long maxSum = 0;
        long currentSum = 0;
        for (int i = 0; i < k; i++) {
            for (int num : arr) {
                currentSum = Math.max(num, currentSum + num);
                maxSum = Math.max(maxSum, currentSum);
            }
        }
        return maxSum % MOD;
    }

    private final int MOD = 1000000007;
}