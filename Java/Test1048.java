import static org.junit.Assert.assertEquals;

import org.junit.Test;

public class Test1048 {
    Solution1048 solution = new Solution1048();

    @Test
    public void Example1() {
        String[] words = new String[] { "a", "b", "ba", "bca", "bda", "bdca" };
        assertEquals(4, solution.longestStrChain(words));
    }

    @Test
    public void Example2() {
        String[] words = new String[] { "xbc", "pcxbcf", "xb", "cxbc", "pcxbc" };
        assertEquals(5, solution.longestStrChain(words));
    }

    @Test
    public void Example3() {
        String[] words = new String[] { "abcd", "dbqca" };
        assertEquals(1, solution.longestStrChain(words));
    }
}
