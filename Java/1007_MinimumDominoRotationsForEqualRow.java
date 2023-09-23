class Solution1007 {
    public int minDominoRotations(int[] tops, int[] bottoms) {
        int n = tops.length;
        int[] count = new int[7];
        for (int i = 0; i < n; i++) {
            count[tops[i]]++;
            if (tops[i] != bottoms[i])
                count[bottoms[i]]++;
        }
        for (int i = 1; i <= 6; i++) {
            if (count[i] == n) {
                int top = 0, bottom = 0;
                for (int j = 0; j < n; j++) {
                    if (tops[j] != i)
                        top++;
                    if (bottoms[j] != i)
                        bottom++;
                }
                return Math.min(top, bottom);
            }
        }
        return -1;
    }
}