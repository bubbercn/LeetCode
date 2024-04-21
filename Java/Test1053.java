import static org.junit.Assert.assertArrayEquals;

import org.junit.Test;

public class Test1053 {
    Solution1053 solution = new Solution1053();

    @Test
    public void Example1() {
        int[] arr = { 3, 2, 1 };
        int[] expected = { 3, 1, 2 };
        assertArrayEquals(expected, solution.prevPermOpt1(arr));
    }

    @Test
    public void Example2() {
        int[] arr = { 1, 1, 5 };
        int[] expected = { 1, 1, 5 };
        assertArrayEquals(expected, solution.prevPermOpt1(arr));
    }

    @Test
    public void Example3() {
        int[] arr = { 1, 9, 4, 6, 7 };
        int[] expected = { 1, 7, 4, 6, 9 };
        assertArrayEquals(expected, solution.prevPermOpt1(arr));
    }
}
