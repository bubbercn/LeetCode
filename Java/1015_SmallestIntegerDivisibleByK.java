import java.util.HashSet;
import java.util.Set;

class Solution1015 {
    public int smallestRepunitDivByK(int k) {
        Set<Integer> remainders = new HashSet<>();
        int result = 1;
        int remainder = result % k;
        while (remainder != 0) {
            if (!remainders.add(remainder))
                return -1;
            remainder = (remainder * 10 + 1) % k;
            result++;
        }
        return result;
    }
}