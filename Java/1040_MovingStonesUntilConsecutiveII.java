import java.util.Arrays;

class Solution1040 {
    public int[] numMovesStonesII(int[] stones) {
        Arrays.sort(stones);
        int n = stones.length;
        int max = Math.max(stones[n - 2] - stones[0] + 2 - n, stones[n - 1] - stones[1] + 2 - n);
        if (stones[n - 1] - stones[0] == n - 1)
            return new int[] { 0, max };
        int count = 0;
        int maxCount = 0;
        int left = 0;
        int right = 0;
        while (right < n) {
            if (stones[right] < stones[left] + n) {
                count++;
                if (count == n - 1 && stones[right] != stones[left] + n - 1) {
                    maxCount = Math.max(maxCount, 2);
                } else {
                    maxCount = Math.max(maxCount, count);
                }
                right++;
            } else {
                count--;
                left++;
            }
        }
        int min = n - maxCount;
        return new int[] { min, max };
    }
}