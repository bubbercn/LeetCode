import static org.junit.Assert.assertEquals;

import org.junit.Test;

public class Test1009 {
    Solution1009 solution = new Solution1009();

    @Test
    public void Example1() {
        assertEquals(solution.bitwiseComplement(5), 2);
    }

    @Test
    public void Example2() {
        assertEquals(solution.bitwiseComplement(7), 0);
    }

    @Test
    public void Example3() {
        assertEquals(solution.bitwiseComplement(10), 5);
    }

    @Test
    public void Failure1() {
        assertEquals(solution.bitwiseComplement(0), 1);
    }
}
