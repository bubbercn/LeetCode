import static org.junit.Assert.assertEquals;

import org.junit.Test;

public class Test1106 {
    Solution1106 solution = new Solution1106();

    @Test
    public void Example1() {
        assertEquals(false, solution.parseBoolExpr("&(|(f))"));
    }

    @Test
    public void Example2() {
        assertEquals(true, solution.parseBoolExpr("|(f,f,f,t)"));
    }

    @Test
    public void Example3() {
        assertEquals(true, solution.parseBoolExpr("!(&(f,t))"));
    }

    @Test
    public void Case1() {
        assertEquals(false, solution.parseBoolExpr("f"));
    }

    @Test
    public void Case2() {
        assertEquals(true, solution.parseBoolExpr("t"));
    }

    @Test
    public void Failure1() {
        assertEquals(true, solution.parseBoolExpr("&(t,t,t)"));
    }
}
