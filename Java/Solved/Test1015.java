import static org.junit.Assert.assertEquals;

import org.junit.Test;

public class Test1015 {
    Solution1015 solution = new Solution1015();

    @Test
    public void Example1() {
        assertEquals(solution.smallestRepunitDivByK(1), 1);
    }

    @Test
    public void Example2() {
        assertEquals(solution.smallestRepunitDivByK(2), -1);
    }

    @Test
    public void Example3() {
        assertEquals(solution.smallestRepunitDivByK(3), 3);
    }
}
