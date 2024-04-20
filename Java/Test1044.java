import static org.junit.Assert.assertEquals;

import org.junit.Test;

public class Test1044 {
    Solution1044 solution = new Solution1044();

    @Test
    public void Example1() {
        String s = "banana";
        assertEquals("ana", solution.longestDupSubstring(s));
    }

    @Test
    public void Example2() {
        String s = "abcd";
        assertEquals("", solution.longestDupSubstring(s));
    }

    @Test public void Failure1() {
        String s = "xnahfslefuigqaaaaaaaaaaaaa";
        assertEquals("aaaaaaaaaaaa", solution.longestDupSubstring(s));
    }
}
