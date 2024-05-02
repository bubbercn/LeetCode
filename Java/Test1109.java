import static org.junit.Assert.assertArrayEquals;

import org.junit.Test;

public class Test1109 {
    Solution1109 solution = new Solution1109();

    @Test
    public void Example1() {
        int[] expected = new int[] { 10, 55, 45, 25, 25 };
        int[][] bookings = new int[][] { { 1, 2, 10 }, { 2, 3, 20 }, { 2, 5, 25 } };
        assertArrayEquals(expected, solution.corpFlightBookings(bookings, 5));
    }

    @Test
    public void Example2() {
        int[] expected = new int[] { 10, 25 };
        int[][] bookings = new int[][] { { 1, 2, 10 }, { 2, 2, 15 } };
        assertArrayEquals(expected, solution.corpFlightBookings(bookings, 2));
    }
}
