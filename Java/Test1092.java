import static org.junit.Assert.assertEquals;

import org.junit.Test;

public class Test1092 {
    Solution1092 solution = new Solution1092();

    @Test
    public void Example1() {
        assertEquals("cabac", solution.shortestCommonSupersequence("abac", "cab"));
    }

    @Test
    public void Example2() {
        assertEquals("aaaaaaaa", solution.shortestCommonSupersequence("aaaaaaaa", "aaaaaaaa"));
    }

    @Test
    public void Failure1() {
        assertEquals("bbbaaababbb", solution.shortestCommonSupersequence("bbbaaaba", "bbababbb"));
    }
}
