class Solution1093 {
    public double[] sampleStats(int[] count) {
        int n = count.length;
        int total = 0;
        double sum = 0;
        int min = Integer.MAX_VALUE;
        int max = Integer.MIN_VALUE;
        int mode = 0;
        int modeCount = 0;
        for (int i = 0; i < n; i++) {
            if (count[i] > 0) {
                total += count[i];
                sum += (double) i * count[i];
                min = Math.min(min, i);
                max = Math.max(max, i);
                if (count[i] > modeCount) {
                    modeCount = count[i];
                    mode = i;
                }
            }
        }
        double mean = (double) sum / total;
        double median = 0;
        int half = (total + 1) / 2;
        int countSoFar = 0;
        for (int i = 0; i < n; i++) {
            countSoFar += count[i];
            if (countSoFar >= half) {
                if (total % 2 == 1 || countSoFar > half) {
                    median = i;
                } else {
                    int next = i + 1;
                    while (count[next] == 0) {
                        next++;
                    }
                    median = (i + next) / 2.0;
                }
                break;
            }
        }

        return new double[] { min, max, mean, median, mode };
    }
}