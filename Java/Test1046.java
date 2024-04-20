import static org.junit.Assert.assertEquals;

import org.junit.Test;

public class Test1046 {
    Solution1046 solution = new Solution1046();

    @Test
    public void Example1() {
        int[] stones = { 2, 7, 4, 1, 8, 1 };
        assertEquals(1, solution.lastStoneWeight(stones));
    }

    @Test
    public void Example2() {
        int[] stones = { 1 };
        assertEquals(1, solution.lastStoneWeight(stones));
    }
}
