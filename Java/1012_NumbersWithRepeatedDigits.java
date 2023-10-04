import java.util.HashSet;
import java.util.Set;

class Solution1012 {
    public int numDupDigitsAtMostN(int n) {
        return n + 1 - numNoDuplicate(n);
    }

    private int numNoDuplicate(int n) {
        if (n < 10) {
            return n + 1;
        }
        String s = String.valueOf(n);
        int digitCount = s.length();
        int result = 10;
        for (int i = 2; i < digitCount; i++) {
            result += 9 * helper(i - 1, 9);
        }
        boolean[] occupied = new boolean[10];
        for (int i = 0; i < digitCount; i++) {
            int digit = s.charAt(i) - '0';
            Set<Integer> candidates = new HashSet<>();
            for (int j = 0; j < digit; j++) {
                candidates.add(j);
            }
            if (i == 0)
                candidates.remove(0);
            for (int j = 0; j < i; j++) {
                candidates.remove(s.charAt(j) - '0');
            }
            int candidateCount = candidates.size();
            if (candidateCount != 0) {
                result += candidateCount * helper(digitCount - i - 1, 9 - i);

            }
            if (occupied[digit])
                break;
            occupied[digit] = true;
        }
        if (!hasDuplicate(n)) {
            result++;
        }
        return result;
    }

    private int helper(int digitCount, int left) {
        if (digitCount > left) {
            return 0;
        }
        int result = 1;
        for (int i = 0; i < digitCount; i++) {
            result *= left - i;
        }
        return result;
    }

    Boolean hasDuplicate(int n) {
        String s = String.valueOf(n);
        int[] count = new int[10];
        for (int i = 0; i < s.length(); i++) {
            int digit = s.charAt(i) - '0';
            count[digit]++;
            if (count[digit] > 1) {
                return true;
            }
        }
        return false;
    }
}