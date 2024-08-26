import static org.junit.Assert.assertEquals;

import org.junit.Test;

public class Test1128 {
    Solution1128 solution = new Solution1128();

    @Test
    public void Example1() {
        int[][] dominoes = new int[][] { { 1, 2 }, { 2, 1 }, { 3, 4 }, { 5, 6 } };
        assertEquals(1, solution.numEquivDominoPairs(dominoes));
    }

    @Test
    public void Example2() {
        int[][] dominoes = new int[][] { { 1, 2 }, { 1, 2 }, { 1, 1 }, { 1, 2 }, { 2, 2 } };
        assertEquals(3, solution.numEquivDominoPairs(dominoes));
    }
}
