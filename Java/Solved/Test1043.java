import static org.junit.Assert.assertEquals;

import org.junit.Test;

public class Test1043 {
    Solution1043 solution = new Solution1043();

    @Test
    public void Example1() {
        int[] arr = new int[] { 1, 15, 7, 9, 2, 5, 10 };
        assertEquals(84, solution.maxSumAfterPartitioning(arr, 3));
    }

    @Test
    public void Example2() {
        int[] arr = new int[] { 1, 4, 1, 5, 7, 3, 6, 1, 9, 9, 3 };
        assertEquals(83, solution.maxSumAfterPartitioning(arr, 4));
    }

    @Test
    public void Example3() {
        int[] arr = new int[] { 1 };
        assertEquals(1, solution.maxSumAfterPartitioning(arr, 1));
    }
}
