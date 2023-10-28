import static org.junit.Assert.assertEquals;

import org.junit.Test;

public class Test1017 {
    Solution1017 solution = new Solution1017();

    @Test
    public void Example1() {
        assertEquals(solution.baseNeg2(2), "110");
    }

    @Test
    public void Example2() {
        assertEquals(solution.baseNeg2(3), "111");
    }

    @Test
    public void Example3() {
        assertEquals(solution.baseNeg2(4), "100");
    }

    @Test
    public void Failure1() {
        assertEquals(solution.baseNeg2(5), "101");
    }
}
