import static org.junit.Assert.assertEquals;

import org.junit.Test;

public class Test1061 {
    Solution1061 solution = new Solution1061();

    @Test
    public void Example1() {
        String s1 = "parker";
        String s2 = "morris";
        String baseStr = "parser";
        String expected = "makkek";
        assertEquals(expected, solution.smallestEquivalentString(s1, s2, baseStr));
    }

    @Test
    public void Example2() {
        String s1 = "hello";
        String s2 = "world";
        String baseStr = "hold";
        String expected = "hdld";
        assertEquals(expected, solution.smallestEquivalentString(s1, s2, baseStr));
    }

    @Test
    public void Example3() {
        String s1 = "leetcode";
        String s2 = "programs";
        String baseStr = "sourcecode";
        String expected = "aauaaaaada";
        assertEquals(expected, solution.smallestEquivalentString(s1, s2, baseStr));
    }
}
