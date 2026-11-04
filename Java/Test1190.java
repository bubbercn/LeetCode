import static org.junit.Assert.assertEquals;

import org.junit.Test;

public class Test1190 {
    Solution1190 solution = new Solution1190();

    @Test
    public void Example1() {
        String input = "(abcd)";
        String expected = "dcba";
        assertEquals(expected, solution.reverseParentheses(input));
    }

    @Test
    public void Example2() {
        String input = "(u(love)i)";
        String expected = "iloveu";
        assertEquals(expected, solution.reverseParentheses(input));
    }

    @Test 
    public void Example3() {
        String input = "(ed(et(oc))el)";
        String expected = "leetcode";
        assertEquals(expected, solution.reverseParentheses(input));
    }
}
