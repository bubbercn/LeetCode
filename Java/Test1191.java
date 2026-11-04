import static org.junit.Assert.assertEquals;

import org.junit.Test;

public class Test1191 {
    Solution1191 solution = new Solution1191();

    @Test
    public void Example1() {
        int[] arr = {1, 2, 3};
        int k = 2;
        int result = solution.kConcatenationMaxSum(arr, k);
        assertEquals(9, result);
    }

    @Test
    public void Example2() {
        int[] arr = {1, -2, 1};
        int k = 5;
        int result = solution.kConcatenationMaxSum(arr, k);
        assertEquals(2, result);
    }

    @Test
    public void Example3() {
        int[] arr = {-1, -2};
        int k = 7;
        int result = solution.kConcatenationMaxSum(arr, k);
        assertEquals(0, result);
    }
}
