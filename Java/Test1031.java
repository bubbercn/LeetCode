import static org.junit.Assert.assertEquals;

import org.junit.Test;

public class Test1031 {
    Solution1031 solution1031 = new Solution1031();

    @Test
    public void Example1() {
        int[] nums = { 0, 6, 5, 2, 2, 5, 1, 9, 4 };
        assertEquals(20, solution1031.maxSumTwoNoOverlap(nums, 1, 2));
    }

    @Test
    public void Example2() {
        int[] nums = { 3, 8, 1, 3, 2, 1, 8, 9, 0 };
        assertEquals(29, solution1031.maxSumTwoNoOverlap(nums, 3, 2));
    }

    @Test
    public void Example3() {
        int[] nums = { 2, 1, 5, 6, 0, 9, 5, 0, 3, 8 };
        assertEquals(31, solution1031.maxSumTwoNoOverlap(nums, 4, 3));
    }
}
