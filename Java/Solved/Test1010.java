import static org.junit.Assert.assertEquals;

import org.junit.Test;

public class Test1010 {
    Solution1010 solution = new Solution1010();

    @Test
    public void Example1() {
        int[] time = { 30, 20, 150, 100, 40 };
        assertEquals(solution.numPairsDivisibleBy60(time), 3);
    }

    @Test
    public void Example2() {
        int[] time = { 60, 60, 60 };
        assertEquals(solution.numPairsDivisibleBy60(time), 3);
    }
}
