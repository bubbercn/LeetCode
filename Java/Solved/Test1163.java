import static org.junit.Assert.assertEquals;

import org.junit.Test;

public class Test1163 {
    Solution1163 solution = new Solution1163();

    @Test
    public void Example1() {
        assertEquals("bab", solution.lastSubstring("abab"));
    }

    @Test
    public void Example2() {
        assertEquals("tcode", solution.lastSubstring("leetcode"));
    }
}
