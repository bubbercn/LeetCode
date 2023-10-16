import static org.junit.Assert.assertEquals;

import org.junit.Test;

public class Test1027 {
    Solution1027 solution = new Solution1027();

    @Test
    public void Example1() {
        int[] nums = { 3, 6, 9, 12 };
        assertEquals(4, solution.longestArithSeqLength(nums));
    }

    @Test
    public void Example2() {
        int[] nums = { 9, 4, 7, 2, 10 };
        assertEquals(3, solution.longestArithSeqLength(nums));
    }

    @Test
    public void Example3() {
        int[] nums = { 20, 1, 15, 3, 10, 5, 8 };
        assertEquals(4, solution.longestArithSeqLength(nums));
    }
}
