import static org.junit.Assert.assertEquals;

import org.junit.Test;

public class Test1186 {
    Solution1186 solution = new Solution1186();

    @Test
    public void Example1() {
        int[] arr = { 1, -2, 0, 3 };
        int expected = 4;
        assertEquals(expected, solution.maximumSum(arr));
    }

    @Test
    public void Example2() {
        int[] arr = { 1, -2, -2, 3 };
        int expected = 3;
        assertEquals(expected, solution.maximumSum(arr));
    }

    @Test
    public void Example3() {
        int[] arr = { -1, -1, -1, -1 };
        int expected = -1;
        assertEquals(expected, solution.maximumSum(arr));
    }

    @Test
    public void Failure1() {
        int[] arr = { 1, -4, -5, -2, 5, 0, -1, 2 };
        int expected = 7;
        assertEquals(expected, solution.maximumSum(arr));
    }

    @Test
    public void Failure2() {
        int[] arr = { 11, -10, -11, 8, 7, -6, 9, 4, 11, 6, 5, 0 };
        int expected = 50;
        assertEquals(expected, solution.maximumSum(arr));
    }
}
