import static org.junit.Assert.assertEquals;

import org.junit.Test;

public class Test1005 {
    Solution1005 solution = new Solution1005();

    @Test
    public void Example1() {
        int[] nums = { 4, 2, 3 };
        assertEquals(solution.largestSumAfterKNegations(nums, 1), 5);
    }

    @Test
    public void Example2() {
        int[] nums = { 3, -1, 0, 2 };
        assertEquals(solution.largestSumAfterKNegations(nums, 3), 6);
    }

    @Test
    public void Example3() {
        int[] nums = { 2, -3, -1, 5, -4 };
        assertEquals(solution.largestSumAfterKNegations(nums, 2), 13);
    }
}
