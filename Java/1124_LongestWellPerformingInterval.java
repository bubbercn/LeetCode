class Solution1124 {
    public int longestWPI(int[] hours) {
        int result = 0;
        int length = 0;
        int count = 0;
        for (int i = 0; i < hours.length; i++) {
            if (hours[i] > 8) {
                count++;
            } else {
                count--;
            }
            if (count < 0) {
                count = 0;
            }
            if (count > 0) {
                length++;
            } else {
                length = 0;
            }
            result = Math.max(result, length);
        }
        return result;
    }
}