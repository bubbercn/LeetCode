import java.util.Arrays;

class Solution1033 {
    public int[] numMovesStones(int a, int b, int c) {
        int[] result = new int[2];
        int[] slots = new int[3];
        slots[0] = a;
        slots[1] = b;
        slots[2] = c;
        Arrays.sort(slots);
        if (slots[2] - slots[0] == 2) {
            result[0] = 0;
            result[1] = 0;
            return result;
        }
        if (Math.abs(slots[0] - slots[1]) <= 2 || Math.abs(slots[1] - slots[2]) <= 2) {
            result[0] = 1;
        } else {
            result[0] = 2;
        }
        result[1] = slots[2] - slots[0] - 2;
        return result;
    }
}