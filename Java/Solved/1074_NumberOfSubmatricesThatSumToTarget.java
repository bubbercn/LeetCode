class Solution1074 {
    public int numSubmatrixSumTarget(int[][] matrix, int target) {
        int m = matrix.length;
        int n = matrix[0].length;
        int[][] prefixSum = new int[m + 1][n + 1];
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                prefixSum[i][j] = matrix[i - 1][j - 1] + prefixSum[i - 1][j] + prefixSum[i][j - 1]
                        - prefixSum[i - 1][j - 1];
            }
        }
        int result = 0;
        for (int x1 = 0; x1 < m; x1++) {
            for (int y1 = 0; y1 < n; y1++) {
                for (int x2 = x1 + 1; x2 <= m; x2++) {
                    for (int y2 = y1 + 1; y2 <= n; y2++) {
                        int sum = prefixSum[x2][y2] - prefixSum[x1][y2] - prefixSum[x2][y1]
                                + prefixSum[x1][y1];
                        if (sum == target) {
                            result++;
                        }
                    }
                }
            }
        }
        return result;
    }
}