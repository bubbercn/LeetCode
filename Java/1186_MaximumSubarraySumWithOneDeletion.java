class Solution1186 {
    public int maximumSum(int[] arr) {
        int n = arr.length;
        int dp0 = arr[0];
        int dp1 = 0;
        int result = arr[0];
        for (int i = 1; i < n; i++) {
            dp1 = Math.max(dp1 + arr[i], dp0);
            dp0 = Math.max(dp0, 0) + arr[i];
            result = Math.max(result, Math.max(dp0, dp1));
        }
        return result;
    }
}