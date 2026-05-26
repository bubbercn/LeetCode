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
}
