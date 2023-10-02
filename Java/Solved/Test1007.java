import static org.junit.Assert.assertEquals;

import org.junit.Test;

public class Test1007 {
    Solution1007 solution = new Solution1007();

    @Test
    public void Example1() {
        int[] tops = { 2, 1, 2, 4, 2, 2 };
        int[] bottoms = { 5, 2, 6, 2, 3, 2 };
        assertEquals(solution.minDominoRotations(tops, bottoms), 2);
    }

    @Test
    public void Example2() {
        int[] tops = { 3, 5, 1, 2, 3 };
        int[] bottoms = { 3, 6, 3, 3, 4 };
        assertEquals(solution.minDominoRotations(tops, bottoms), -1);
    }
}
