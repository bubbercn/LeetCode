import static org.junit.Assert.assertEquals;

import org.junit.Test;

public class Test1071 {
    Solution1071 solution1071 = new Solution1071();

    @Test
    public void Example1() {
        String str1 = "ABCABC";
        String str2 = "ABC";
        String expected = "ABC";
        assertEquals(expected, solution1071.gcdOfStrings(str1, str2));
    }

    @Test
    public void Example2() {
        String str1 = "ABABAB";
        String str2 = "ABAB";
        String expected = "AB";
        assertEquals(expected, solution1071.gcdOfStrings(str1, str2));
    }

    @Test
    public void Example3() {
        String str1 = "LEET";
        String str2 = "CODE";
        String expected = "";
        assertEquals(expected, solution1071.gcdOfStrings(str1, str2));
    }
}
