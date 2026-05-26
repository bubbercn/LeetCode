import static org.junit.Assert.assertEquals;

import org.junit.Test;

public class Test1184 {
    Solution1184 solution = new Solution1184();

    @Test
    public void Example1() {
        int[] distance = { 1, 2, 3, 4 };
        int start = 0;
        int destination = 1;
        int expected = 1;
        assertEquals(expected, solution.distanceBetweenBusStops(distance, start, destination));
    }

    @Test
    public void Example2() {
        int[] distance = { 1, 2, 3, 4 };
        int start = 0;
        int destination = 2;
        int expected = 3;
        assertEquals(expected, solution.distanceBetweenBusStops(distance, start, destination));
    }

    @Test
    public void Example3() {
        int[] distance = { 1, 2, 3, 4 };
        int start = 0;
        int destination = 3;
        int expected = 4;
        assertEquals(expected, solution.distanceBetweenBusStops(distance, start, destination));
    }
}
