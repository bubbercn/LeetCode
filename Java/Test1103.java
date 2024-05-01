import static org.junit.Assert.assertArrayEquals;

import org.junit.Test;

public class Test1103 {
    Solution1103 solution = new Solution1103();

    @Test
    public void Example1() {
        int[] expected = new int[] { 1, 2, 3, 1 };
        assertArrayEquals(expected, solution.distributeCandies(7, 4));
    }

    @Test
    public void Example2() {
        int[] expected = new int[] { 5, 2, 3 };
        assertArrayEquals(expected, solution.distributeCandies(10, 3));
    }
}
