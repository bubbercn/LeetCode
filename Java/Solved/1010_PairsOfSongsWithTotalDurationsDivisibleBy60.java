class Solution1010 {
    public int numPairsDivisibleBy60(int[] time) {
        int[] remainders = new int[60];
        for (int t : time) {
            remainders[t % 60]++;
        }
        int result = 0;
        for (int i = 1; i < 30; i++) {
            result += remainders[i] * remainders[60 - i];
        }
        result += (long)remainders[0] * (remainders[0] - 1) / 2;
        result += (long)remainders[30] * (remainders[30] - 1) / 2;
        return result;
    }
}