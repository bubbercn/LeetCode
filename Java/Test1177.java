import static org.junit.Assert.assertEquals;

import java.util.List;

import org.junit.Test;

public class Test1177 {
    Solution1177 solution = new Solution1177();

    @Test
    public void Example1() {
        String s = "abcda";
        int[][] queries = { { 3, 3, 0 }, { 1, 2, 0 }, { 0, 3, 1 }, { 0, 3, 2 }, { 0, 4, 1 } };
        List<Boolean> expected = List.of(true, false, false, true, true);
        assertEquals(expected, solution.canMakePaliQueries(s, queries));
    }

    @Test
    public void Example2() {
        String s = "lyb";
        int[][] queries = { { 0, 1, 0 }, { 2, 2, 1 } };
        List<Boolean> expected = List.of(false, true);
        assertEquals(expected, solution.canMakePaliQueries(s, queries));
    }

    @Test
    public void Failure1() {
        String s = "hunu";
        int[][] queries = { { 0, 3, 1 } };
        List<Boolean> expected = List.of(true);
        assertEquals(expected, solution.canMakePaliQueries(s, queries));
    }
}
