class Solution1014 {
    public int maxScoreSightseeingPair(int[] values) {
        int result = 0;
        int pv = values[0];
        for (int i = 1; i < values.length; i++) {
            pv--;
            result = Math.max(result, pv + values[i]);
            pv = Math.max(pv, values[i]);
        }
        return result;
    }
}