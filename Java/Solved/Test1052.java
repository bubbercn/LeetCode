import static org.junit.Assert.assertEquals;

import org.junit.Test;

public class Test1052 {
    Solution1052 solution = new Solution1052();

    @Test
    public void Example1() {
        int[] customers = { 1, 0, 1, 2, 1, 1, 7, 5 };
        int[] grumpy = { 0, 1, 0, 1, 0, 1, 0, 1 };
        int minutes = 3;
        assertEquals(16, solution.maxSatisfied(customers, grumpy, minutes));
    }

    @Test
    public void Example2() {
        int[] customers = { 1 };
        int[] grumpy = { 0 };
        int minutes = 1;
        assertEquals(1, solution.maxSatisfied(customers, grumpy, minutes));
    }
}
