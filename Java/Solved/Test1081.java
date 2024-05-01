import static org.junit.Assert.assertEquals;

import org.junit.Test;

public class Test1081 {
    Solution1081 solution = new Solution1081();

    @Test
    public void Example1() {
        assertEquals("abc", solution.smallestSubsequence("bcabc"));
    }

    @Test
    public void Example2() {
        assertEquals("acdb", solution.smallestSubsequence("cbacdcbc"));
    }
}
