import static org.junit.Assert.assertArrayEquals;

import org.junit.Test;

public class Test1078 {
    Solution1078 solution = new Solution1078();

    @Test
    public void Example1() {
        String[] expected = { "girl", "student" };
        assertArrayEquals(expected, solution.findOcurrences("alice is a good girl she is a good student", "a", "good"));
    }

    @Test
    public void Example2() {
        String[] expected = { "we", "rock" };
        assertArrayEquals(expected, solution.findOcurrences("we will we will rock you", "we", "will"));
    }
}
