import static org.junit.Assert.assertEquals;

import org.junit.Test;

public class Test1003 {

    Solution1003 solution = new Solution1003();

    @Test
    public void Example1() {
        assertEquals(solution.isValid("aabcbc"), true);
    }

    @Test
    public void Example2() {
        assertEquals(solution.isValid("abcabcababcc"), true);
    }

    @Test
    public void Example3() {
        assertEquals(solution.isValid("abccba"), false);
    }
}
