import static org.junit.Assert.assertEquals;

import org.junit.Test;

public class Test1041 {
    Solution1041 solution = new Solution1041();

    @Test
    public void Example1() {
        String instructions = "GGLLGG";
        assertEquals(true, solution.isRobotBounded(instructions));
    }

    @Test
    public void Example2() {
        String instructions = "GG";
        assertEquals(false, solution.isRobotBounded(instructions));
    }

    @Test
    public void Example3() {
        String instructions = "GL";
        assertEquals(true, solution.isRobotBounded(instructions));
    }
}
