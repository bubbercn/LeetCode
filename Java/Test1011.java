import static org.junit.Assert.assertEquals;

import org.junit.Test;

public class Test1011 {
    Solution1011 solution = new Solution1011();

    @Test
    public void Example1() {
        int[] weights = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
        assertEquals(solution.shipWithinDays(weights, 5), 15);
    }

    @Test
    public void Example2() {
        int[] weights = { 3, 2, 2, 4, 1, 4 };
        assertEquals(solution.shipWithinDays(weights, 3), 6);
    }

    public void Example3() {
        int[] weights = { 1, 2, 3, 1, 1 };
        assertEquals(solution.shipWithinDays(weights, 4), 3);
    }
}
