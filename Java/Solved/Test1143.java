import static org.junit.Assert.assertEquals;

import org.junit.Test;

public class Test1143 {
    Solution1143 solution = new Solution1143();

    @Test
    public void Example1() {
        String text1 = "abcde", text2 = "ace";
        assertEquals(3, solution.longestCommonSubsequence(text1, text2));
    }

    @Test
    public void Example2() {
        String text1 = "abc", text2 = "abc";
        assertEquals(3, solution.longestCommonSubsequence(text1, text2));
    }

    @Test
    public void Example3() {
        String text1 = "abc", text2 = "def";
        assertEquals(0, solution.longestCommonSubsequence(text1, text2));
    }
}
