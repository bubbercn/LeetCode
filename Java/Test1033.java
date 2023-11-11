import static org.junit.Assert.assertArrayEquals;

import org.junit.Test;

public class Test1033 {
    Solution1033 solution = new Solution1033();

    @Test
    public void Example1() {
        int[] expected = { 1, 2 };
        assertArrayEquals(expected, solution.numMovesStones(1, 2, 5));
    }

    @Test
    public void Example2() {
        int[] expected = { 0, 0 };
        assertArrayEquals(expected, solution.numMovesStones(4, 3, 2);
    }

    @Test
    public void Example3() {
        int[] expected = { 1, 2 };
        assertArrayEquals(expected, solution.numMovesStones(3, 5, 1));
    }
}
