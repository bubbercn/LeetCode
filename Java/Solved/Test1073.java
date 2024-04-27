import static org.junit.Assert.assertArrayEquals;

import org.junit.Test;

public class Test1073 {
    Solution1073 solution1073 = new Solution1073();

    @Test
    public void Example1() {
        int[] arr1 = { 1, 1, 1, 1, 1 };
        int[] arr2 = { 1, 0, 1 };
        int[] expected = { 1, 0, 0, 0, 0 };
        assertArrayEquals(expected, solution1073.addNegabinary(arr1, arr2));
    }

    @Test
    public void Example2() {
        int[] arr1 = { 0 };
        int[] arr2 = { 0 };
        int[] expected = { 0 };
        assertArrayEquals(expected, solution1073.addNegabinary(arr1, arr2));
    }

    @Test
    public void Example3() {
        int[] arr1 = { 0 };
        int[] arr2 = { 1 };
        int[] expected = { 1 };
        assertArrayEquals(expected, solution1073.addNegabinary(arr1, arr2));
    }
}
