import static org.junit.Assert.assertEquals;

import org.junit.Test;

public class Test1090 {
    Solution1090 solution = new Solution1090();

    @Test
    public void Example1() {
        int[] values = { 5, 4, 3, 2, 1 };
        int[] labels = { 1, 1, 2, 2, 3 };
        assertEquals(9, solution.largestValsFromLabels(values, labels, 3, 1));
    }

    @Test
    public void Example2() {
        int[] values = { 5, 4, 3, 2, 1 };
        int[] labels = { 1, 3, 3, 3, 2 };
        assertEquals(12, solution.largestValsFromLabels(values, labels, 3, 2));
    }

    @Test
    public void Example3() {
        int[] values = { 9, 8, 8, 7, 6 };
        int[] labels = { 0, 0, 0, 1, 1 };
        assertEquals(16, solution.largestValsFromLabels(values, labels, 3, 2));
    }
}