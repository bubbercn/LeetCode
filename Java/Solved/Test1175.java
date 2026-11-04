import static org.junit.Assert.assertEquals;

import org.junit.Test;

public class Test1175 {
    Solution1175 solution = new Solution1175();

    @Test
    public void Example1() {
        int n = 5;
        int expected = 12;
        assertEquals(expected, solution.numPrimeArrangements(n));
    }

    @Test
    public void Example2() {
        int n = 100;
        int expected = 682289015;
        assertEquals(expected, solution.numPrimeArrangements(n));
    }
}
