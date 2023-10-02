class Solution1006 {
    public int clumsy(int n) {
        int[] temp = getNextTree(n);
        int result = temp[0];
        n = temp[1];
        while (n > 0) {
            result += n;
            n--;
            temp = getNextTree(n);
            result -= temp[0];
            n = temp[1];
        }
        return result;
    }

    private int[] getNextTree(int n) {
        if (n == 0)
            return new int[] { 0, 0 };
        int r = n;
        n--;
        if (n > 0) {
            r *= n;
            n--;
        }
        if (n > 0) {
            r /= n;
            n--;
        }
        int[] result = { r, n };
        return result;
    }
}