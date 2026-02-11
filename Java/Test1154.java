import static org.junit.Assert.assertEquals;

import org.junit.Test;

public class Test1154 {
    Solution1154 solution = new Solution1154();

    @Test
    public void Example1() {
        String date = "2019-01-09";
        assertEquals(9, solution.dayOfYear(date));
    }

    @Test
    public void Example2() {
        String date = "2019-02-10";
        assertEquals(41, solution.dayOfYear(date));
    }
}