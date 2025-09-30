import static org.junit.Assert.assertEquals;

import org.junit.Test;

public class Test1147 {
    Solution1147 solution = new Solution1147();

    @Test
    public void Example1() {
        String text = "ghiabcdefhelloadamhelloabcdefghi";
        assertEquals(7, solution.longestDecomposition(text));
    }

    @Test
    public void Example2() {
        String text = "merchant";
        assertEquals(1, solution.longestDecomposition(text));
    }

    @Test
    public void Example3() {
        String text = "antaprezatepzapreanta";
        assertEquals(11, solution.longestDecomposition(text));
    }
}
