import static org.junit.Assert.assertEquals;

import org.junit.Test;

public class Test1049 {
    Solution1049 solution = new Solution1049();

    @Test
    public void Example1() {
        int[] stones = new int[] { 2, 7, 4, 1, 8, 1 };
        assertEquals(1, solution.lastStoneWeightII(stones));
    }

    @Test
    public void Example2() {
        int[] stones = new int[] { 31, 26, 33, 21, 40 };
        assertEquals(5, solution.lastStoneWeightII(stones));
    }
}
