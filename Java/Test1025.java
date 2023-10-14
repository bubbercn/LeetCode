import static org.junit.Assert.assertEquals;

import org.junit.Test;

public class Test1025 {
    Solution1025 solution = new Solution1025();

    @Test
    public void Example1() {
        assertEquals(true, solution.divisorGame(2));
    }

    @Test
    public void Example2() {
        assertEquals(false, solution.divisorGame(3));
    }
}
