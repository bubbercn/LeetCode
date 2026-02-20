class Solution1131 {
    public int maxAbsValExpr(int[] arr1, int[] arr2) {
        int n = arr1.length;
        int result = 0;

        int[][] coeffs = {
                { 1, 1, 1 },
                { 1, 1, -1 },
                { 1, -1, 1 },
                { -1, 1, 1 }
        };

        for (int[] coeff : coeffs) {
            int max = Integer.MIN_VALUE;
            int min = Integer.MAX_VALUE;

            for (int i = 0; i < n; i++) {
                int value = coeff[0] * arr1[i] + coeff[1] * arr2[i] + coeff[2] * i;
                max = Math.max(max, value);
                min = Math.min(min, value);
            }

            result = Math.max(result, max - min);
        }

        return result;
    }
}