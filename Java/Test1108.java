import static org.junit.Assert.assertEquals;

import org.junit.Test;

public class Test1108 {
    Solution1108 solution = new Solution1108();

    @Test
    public void Example1() {
        assertEquals("1[.]1[.]1[.]1", solution.defangIPaddr("1.1.1.1"));
    }

    @Test
    public void Example2() {
        assertEquals("255[.]100[.]50[.]0", solution.defangIPaddr("255.100.50.0"));
    }
}
