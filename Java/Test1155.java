import static org.junit.Assert.assertEquals;

import org.junit.Test;

public class Test1155 {
    Solution1155 solution = new Solution1155();

    @Test
    public void Example1() {
        int n = 1, k = 6, target = 3;
        assertEquals(1, solution.numRollsToTarget(n, k, target));
    }

    @Test
    public void Example2() {
        int n = 2, k = 6, target = 7;
        assertEquals(6, solution.numRollsToTarget(n, k, target));
    }

    @Test
    public void Example3() {
        int n = 30, k = 30, target = 500;
        assertEquals(222616187, solution.numRollsToTarget(n, k, target));
    }
}
