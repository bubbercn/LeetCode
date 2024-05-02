import static org.junit.Assert.assertEquals;

import org.junit.Test;

public class Test1105 {
    Solution1105 solution = new Solution1105();

    @Test
    public void Example1() {
        int[][] books = { { 1, 1 }, { 2, 3 }, { 2, 3 }, { 1, 1 }, { 1, 1 }, { 1, 1 }, { 1, 2 } };
        assertEquals(6, solution.minHeightShelves(books, 4));
    }

    @Test
    public void Example2() {
        int[][] books = { { 1, 3 }, { 2, 4 }, { 3, 2 } };
        assertEquals(4, solution.minHeightShelves(books, 6));
    }
}
