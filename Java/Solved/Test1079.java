import static org.junit.Assert.assertEquals;

import org.junit.Test;

public class Test1079 {
    Solution1079 solution = new Solution1079();

    @Test
    public void Example1() {
        assertEquals(8, solution.numTilePossibilities("AAB"));
    }

    @Test
    public void Example2() {
        assertEquals(188, solution.numTilePossibilities("AAABBC"));
    }

    @Test
    public void Example3() {
        assertEquals(1, solution.numTilePossibilities("V"));
    }
}
