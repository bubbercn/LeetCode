import static org.junit.Assert.assertEquals;

import org.junit.Test;

public class Test1124 {
    Solution1124 solution = new Solution1124();

    @Test
    public void Example1() {
        int[] hours = new int[] {9, 9, 6, 0, 6, 6, 9};
        assertEquals(3, solution.longestWPI(hours));
    }

    @Test
    public void Example2() {
        int[] hours = new int[] {6, 6, 6};
        assertEquals(0, solution.longestWPI(hours));
    }

    @Test
    public void Failure1() {
        int[] hours = new int[] {6, 9, 9};
        assertEquals(3, solution.longestWPI(hours));
    }
}
