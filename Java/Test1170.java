import static org.junit.Assert.assertArrayEquals;

import org.junit.Test;

public class Test1170 {
    Solution1170 solution = new Solution1170();

    @Test
    public void Example1() {
        String[] queries = {"cbd"};
        String[] words = {"zaaaz"};
        int[] expected = {1};
        assertArrayEquals(expected, solution.numSmallerByFrequency(queries, words));
    }

    @Test
    public void Example2() {
        String[] queries = {"bbb","cc"};
        String[] words = {"a","aa","aaa","aaaa"};
        int[] expected = {1,2};
        assertArrayEquals(expected, solution.numSmallerByFrequency(queries, words));
    }
}
