import static org.junit.Assert.assertEquals;

import org.junit.Test;

public class Test1004 {
    Solution1004 solution = new Solution1004();

    @Test
    public void Example1() {
        int[] nums = { 1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 0 };
        assertEquals(solution.longestOnes(nums, 2), 6);
    }

    @Test
    public void Example2() {
        int[] nums = { 0, 0, 1, 1, 0, 0, 1, 1, 1, 0, 1, 1, 0, 0, 0, 1, 1, 1, 1 };
        assertEquals(solution.longestOnes(nums, 3), 10);
    }
}
