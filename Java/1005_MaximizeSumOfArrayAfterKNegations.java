import java.util.Arrays;

class Solution1005 {
    public int largestSumAfterKNegations(int[] nums, int k) {
        Integer[] integers = toIntegers(nums);
        Arrays.sort(integers, (a, b) -> Math.abs(b) - Math.abs(a));
        for (int i = 0; i < integers.length && k > 0; i++) {
            if (integers[i] < 0) {
                integers[i] = -integers[i];
                k--;
            }
        }
        if (k % 2 == 1) {
            int n = integers.length;
            integers[n - 1] = -integers[n - 1];
        }
        return Arrays.stream(integers).mapToInt(Integer::intValue).sum();
    }

    private Integer[] toIntegers(int[] nums) {
        Integer[] integers = new Integer[nums.length];
        for (int i = 0; i < nums.length; i++)
            integers[i] = nums[i];
        return integers;
    }
}