import static org.junit.Assert.assertEquals;

import org.junit.Test;

public class Test1047 {
    Solution1047 solution = new Solution1047();

    @Test
    public void Example1() {
        String s = "abbaca";
        assertEquals("ca", solution.removeDuplicates(s));
    }

    @Test
    public void Example2() {
        String s = "azxxzy";
        assertEquals("ay", solution.removeDuplicates(s));
    }
}
