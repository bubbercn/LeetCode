import static org.junit.Assert.assertEquals;

import org.junit.Test;

public class Test1006 {
    Solution1006 solution = new Solution1006();

    @Test
    public void Example1() {
        assertEquals(solution.clumsy(4), 7);
    }

    @Test
    public void Example2() {
        assertEquals(solution.clumsy(10), 12);
    }
}
