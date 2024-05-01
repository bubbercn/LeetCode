import static org.junit.Assert.assertEquals;

import org.junit.Test;

public class Test1094 {
    Solution1094 solution = new Solution1094();

    @Test
    public void Example1() {
        int[][] trips = { { 2, 1, 5 }, { 3, 3, 7 } };
        assertEquals(false, solution.carPooling(trips, 4));
    }

    @Test
    public void Example2() {
        int[][] trips = { { 2, 1, 5 }, { 3, 3, 7 } };
        assertEquals(true, solution.carPooling(trips, 5));
    }
}
