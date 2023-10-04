import static org.junit.Assert.assertEquals;

import org.junit.Test;

public class Test1012 {
    Solution1012 solution = new Solution1012();

    @Test
    public void Example1() {
        assertEquals(solution.numDupDigitsAtMostN(20), 1);
    }

    @Test
    public void Example2() {
        assertEquals(solution.numDupDigitsAtMostN(100), 10);
    }

    @Test
    public void Example3() {
        assertEquals(solution.numDupDigitsAtMostN(1000), 262);
    }

    @Test
    public void Failure1() {
        assertEquals(solution.numDupDigitsAtMostN(1), 0);
    }

    @Test
    public void Failure2() {
        assertEquals(solution.numDupDigitsAtMostN(12), 1);
    }

    @Test
    public void Failure3() {
        assertEquals(solution.numDupDigitsAtMostN(11), 1);
    }

    @Test
    public void Failure4() {
        assertEquals(solution.numDupDigitsAtMostN(111), 13);
    }
}
