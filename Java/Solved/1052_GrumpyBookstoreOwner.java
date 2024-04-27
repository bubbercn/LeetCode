class Solution1052 {
    public int maxSatisfied(int[] customers, int[] grumpy, int minutes) {
        int base = 0;
        for (int i = 0; i < customers.length; i++) {
            if (grumpy[i] == 0) {
                base += customers[i];
            }
        }
        int extra = 0;
        for (int i = 0; i < minutes; i++) {
            if (grumpy[i] == 1) {
                extra += customers[i];
            }
        }
        int max = extra;
        for (int i = minutes; i < customers.length; i++) {
            if (grumpy[i] == 1) {
                extra += customers[i];
            }
            if (grumpy[i - minutes] == 1) {
                extra -= customers[i - minutes];
            }
            max = Math.max(max, extra);
        }
        return base + max;
    }
}