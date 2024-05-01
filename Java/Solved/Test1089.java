import static org.junit.Assert.assertArrayEquals;

import org.junit.Test;

public class Test1089 {
    Solution1089 solution = new Solution1089();

    @Test
    public void Example1() {
        int[] arr = { 1, 0, 2, 3, 0, 4, 5, 0 };
        solution.duplicateZeros(arr);
        int[] expected = { 1, 0, 0, 2, 3, 0, 0, 4 };
        assertArrayEquals(expected, arr);
    }

    @Test
    public void Example2() {
        int[] arr = { 1, 2, 3 };
        solution.duplicateZeros(arr);
        int[] expected = { 1, 2, 3 };
        assertArrayEquals(expected, arr);
    }
}
