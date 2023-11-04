class Solution1031 {
    public int maxSumTwoNoOverlap(int[] nums, int firstLen, int secondLen) {
        return Math.max(helper(nums, firstLen, secondLen), helper(nums, secondLen, firstLen));
    }

    private int helper(int nums[], int firstLen, int secondLen) {
        int n = nums.length;
        int[] dp1 = new int[n];
        int sum = 0;
        for (int i = 0; i < n; i++) {
            sum += nums[i];
            if (i >= firstLen) {
                sum -= nums[i - firstLen];
            }
            if (i >= firstLen - 1) {
                dp1[i] = sum;
            }
            else {
                dp1[i] = -1;
            }
        }
        int [] dp2 = new int[n];
        sum = 0;
        for (int i = n - 1; i >= 0; i--) {
            if (i >= n - secondLen) {
                sum += nums[i];
                dp2[i] = -1;
            }
            else {
                if (dp2[i + 1] == -1 || sum > dp2[i + 1]) {
                    dp2[i] = sum;
                }
                else {
                    dp2[i] = dp2[i + 1];
                }
                sum += nums[i];
                sum -= nums[i + secondLen];
            }
        }
        int result = 0;
        for (int i = firstLen - 1; i < n - secondLen; i++) {
            if (dp1[i] == -1 || dp2[i] == -1) {
                continue;
            }
            result = Math.max(result, dp1[i] + dp2[i]);
        }
        return result;
    }
}