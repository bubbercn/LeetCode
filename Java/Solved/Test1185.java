import static org.junit.Assert.assertEquals;

import org.junit.Test;

public class Test1185 {
    Solution1185 solution = new Solution1185();

    @Test
    public void Example1() {
        int day = 31;
        int month = 8;
        int year = 2019;
        String expected = "Saturday";
        assertEquals(expected, solution.dayOfTheWeek(day, month, year));
    }

    @Test
    public void Example2() {
        int day = 18;
        int month = 7;
        int year = 1999;
        String expected = "Sunday";
        assertEquals(expected, solution.dayOfTheWeek(day, month, year));
    }

    @Test
    public void Example3() {
        int day = 15;
        int month = 8;
        int year = 1993;
        String expected = "Sunday";
        assertEquals(expected, solution.dayOfTheWeek(day, month, year));
    }
}
