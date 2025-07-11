import static org.junit.Assert.assertEquals;

import org.junit.Test;

public class Test1131 {
    Solution1131 solution = new Solution1131();

    @Test
    public void Example1() {
        int[] arr1 = new int[] { 1, 2, 3, 4 };
        int[] arr2 = new int[] { -1, 4, 5, 6 };
        assertEquals(13, solution.maxAbsValExpr(arr1, arr2));
    }

    @Test
    public void Example2() {
        int[] arr1 = new int[] { 1, -2, -5, 0, 10 };
        int[] arr2 = new int[] { 0, -2, -1, -7, -4 };
        assertEquals(20, solution.maxAbsValExpr(arr1, arr2));
    }
}
