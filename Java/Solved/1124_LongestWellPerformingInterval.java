class Solution1124 {
    public int longestWPI(int[] hours) {
        int n = hours.length;
        int[] preSum = new int[n + 1];
        for (int i = 0; i < n; i++) {
            preSum[i + 1] = preSum[i] + (hours[i] > 8 ? 1 : -1);
        }
        int result = 0;
        int min = Integer.MAX_VALUE;
        for (int i = 0; i < n; i++) {
            if (preSum[i] < min) {
                min = preSum[i];
            }
            else {
                continue;
            }
            for (int j = n; j > i; j--) {
                if (preSum[j] - preSum[i] > 0) {
                    if (j - i > result) {
                        result = j - i;
                    }
                    break;
                }
            }
        }
        return result;
    }
}