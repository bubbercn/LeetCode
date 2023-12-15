import static org.junit.Assert.assertEquals;

import org.junit.Test;

public class Test1037 {
    Solution1037 solution = new Solution1037();

    @Test
    public void Example1() {
        int[][] points = { { 1, 1 }, { 2, 3 }, { 3, 2 } };
        assertEquals(true, solution.isBoomerang(points));
    }

    @Test
    public void Example2() {
        int[][] points = { { 1, 1 }, { 2, 2 }, { 3, 3 } };
        assertEquals(false, solution.isBoomerang(points));
    }
}
