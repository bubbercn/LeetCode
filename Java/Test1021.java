import static org.junit.Assert.assertEquals;

import org.junit.Test;

public class Test1021 {
    Solution1021 solution = new Solution1021();

    @Test
    public void Example1() {
        String s = "(()())(())";
        assertEquals("()()()", solution.removeOuterParentheses(s));
    }

    @Test
    public void Example2() {
        String s = "(()())(())(()(()))";
        assertEquals("()()()()(())", solution.removeOuterParentheses(s));
    }

    @Test
    public void Example3() {
        String s = "()()";
        assertEquals("", solution.removeOuterParentheses(s));
    }
}
