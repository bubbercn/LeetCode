import static org.junit.Assert.assertEquals;

import org.junit.Test;

public class Test1137 {
    Solution1137 solution = new Solution1137();

    @Test
    public void Example1() {
        assertEquals(4, solution.tribonacci(4));
    }

    @Test
    public void Example2() {
        assertEquals(1389537, solution.tribonacci(25));
    }
}
