import static org.junit.Assert.assertArrayEquals;

import org.junit.Test;

public class Test1122 {
    Solution1122 solution = new Solution1122();

    @Test
    public void Example1() {
        int[] expected = new int[] { 2, 2, 2, 1, 4, 3, 3, 9, 6, 7, 19 };
        int[] arr1 = new int[] { 2, 3, 1, 3, 2, 4, 6, 7, 9, 2, 19 };
        int[] arr2 = new int[] { 2, 1, 4, 3, 9, 6 };
        assertArrayEquals(expected, solution.relativeSortArray(arr1, arr2));
    }

    @Test
    public void Example2() {
        int[] expected = new int[] { 22, 28, 8, 6, 17, 44 };
        int[] arr1 = new int[] { 28, 6, 22, 8, 44, 17 };
        int[] arr2 = new int[] { 22, 28, 8, 6 };
        assertArrayEquals(expected, solution.relativeSortArray(arr1, arr2));
    }
}
