import static org.junit.Assert.assertEquals;

import org.junit.Test;

public class Test1016 {
    Solution1016 solution = new Solution1016();

    @Test
    public void Example1() {
        assertEquals(solution.queryString("0110", 3), true);
    }

    @Test
    public void Example2() {
        assertEquals(solution.queryString("0110", 4), false);
    }
}
