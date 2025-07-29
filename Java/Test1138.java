import static org.junit.Assert.assertEquals;

import org.junit.Test;

public class Test1138 {
    Solution1138 solution = new Solution1138();

    @Test
    public void Example1() {
        assertEquals("DDR!UURRR!!DDD!", solution.alphabetBoardPath("leet"));
    }

    @Test
    public void Example2() {
        assertEquals("RR!DDRR!UUL!R!", solution.alphabetBoardPath("code"));
    }
}
