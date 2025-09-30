import static org.junit.Assert.assertEquals;

import org.junit.Test;

public class Test1144 {
    Solution1144 solution = new Solution1144();

    @Test
    public void Example1() {
        int[] nums = { 1, 2, 3 };
        assertEquals(2, solution.movesToMakeZigzag(nums));
    }

    @Test
    public void Example2() {
        int[] nums = { 9, 6, 1, 6, 2 };
        assertEquals(4, solution.movesToMakeZigzag(nums));
    }
}
