import static org.junit.Assert.assertEquals;

import java.util.Arrays;
import java.util.List;

import org.junit.Test;

public class Test1023 {
    Solution1023 solution = new Solution1023();

    @Test
    public void Example1() {
        String[] queries = { "FooBar", "FooBarTest", "FootBall", "FrameBuffer", "ForceFeedBack" };
        String pattern = "FB";
        List<Boolean> expected = Arrays.asList(true, false, true, true, false);
        assertEquals(expected, solution.camelMatch(queries, pattern));
    }

    @Test
    public void Example2() {
        String[] queries = { "FooBar", "FooBarTest", "FootBall", "FrameBuffer", "ForceFeedBack" };
        String pattern = "FoBa";
        List<Boolean> expected = Arrays.asList(true, false, true, false, false);
        assertEquals(expected, solution.camelMatch(queries, pattern));
    }

    @Test
    public void Example3() {
        String[] queries = { "FooBar", "FooBarTest", "FootBall", "FrameBuffer", "ForceFeedBack" };
        String pattern = "FoBaT";
        List<Boolean> expected = Arrays.asList(false, true, false, false, false);
        assertEquals(expected, solution.camelMatch(queries, pattern));
    }
}
