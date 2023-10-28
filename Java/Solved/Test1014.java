import static org.junit.Assert.assertEquals;

import org.junit.Test;

public class Test1014 {
    Solution1014 solution = new Solution1014();

    @Test
    public void Example1() {
        int[] values = { 8, 1, 5, 2, 6 };
        assertEquals(solution.maxScoreSightseeingPair(values), 11);
    }

    @Test
    public void Example2() {
        int[] values = { 1, 2 };
        assertEquals(solution.maxScoreSightseeingPair(values), 2);
    }
}
