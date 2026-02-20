import static org.junit.Assert.assertEquals;

import org.junit.Test;

public class Test1140 {
    Solution1140 solution = new Solution1140();

    @Test
    public void Example1() {
        int[] piles = { 2, 7, 9, 4, 4 };
        assertEquals(10, solution.stoneGameII(piles));
    }

    @Test
    public void Example2() {
        int[] piles = { 1, 2, 3, 4, 5, 100 };
        assertEquals(104, solution.stoneGameII(piles));
    }
}
