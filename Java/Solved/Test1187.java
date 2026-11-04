import static org.junit.Assert.assertEquals;

import org.junit.Test;

public class Test1187 {
    Solution1187 solution = new Solution1187();

    @Test
    public void Example1() {
        int[] arr1 = { 1, 5, 3, 6, 7 };
        int[] arr2 = { 1, 3, 2, 4 };
        int expected = 1;
        assertEquals(expected, solution.makeArrayIncreasing(arr1, arr2));
    }

    @Test
    public void Example2() {
        int[] arr1 = { 1, 5, 3, 6, 7 };
        int[] arr2 = { 4, 3, 1 };
        int expected = 2;
        assertEquals(expected, solution.makeArrayIncreasing(arr1, arr2));
    }

    @Test
    public void Example3() {
        int[] arr1 = { 1, 5, 3, 6, 7 };
        int[] arr2 = { 1, 6, 3, 3 };
        int expected = -1;
        assertEquals(expected, solution.makeArrayIncreasing(arr1, arr2));
    }
}
