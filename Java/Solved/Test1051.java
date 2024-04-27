import static org.junit.Assert.assertEquals;

import org.junit.Test;

public class Test1051 {
    Solution1051 solution = new Solution1051();

    @Test
    public void Example1() {
        int[] heights = {1, 1, 4, 2, 1, 3};
        assertEquals(3, solution.heightChecker(heights));
    }

    @Test
    public void Example2() {
        int[] heights = {5, 1, 2, 3, 4};
        assertEquals(5, solution.heightChecker(heights));
    }

    @Test
    public void Example3() {
        int[] heights = {1, 2, 3, 4, 5};
        assertEquals(0, solution.heightChecker(heights));
    }
}
