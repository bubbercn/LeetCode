import static org.junit.Assert.assertEquals;

import org.junit.Test;

public class Test1039 {
    Solution1039 solution = new Solution1039();

    @Test
    public void Example1() {
        int[] values = { 1, 2, 3 };
        assertEquals(6, solution.minScoreTriangulation(values));
    }

    @Test
    public void Example2() {
        int[] values = { 3, 7, 4, 5 };
        assertEquals(144, solution.minScoreTriangulation(values));
    }

    @Test
    public void Example3() {
        int[] values = { 1, 3, 1, 4, 1, 5 };
        assertEquals(13, solution.minScoreTriangulation(values));
    }
}
