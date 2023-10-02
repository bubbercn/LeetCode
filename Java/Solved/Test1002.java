import static org.junit.Assert.assertEquals;

import java.util.List;

import org.junit.Test;

public class Test1002 {

    Solution1002 solution = new Solution1002();

    @Test
    public void Example1() {
        String[] words = { "bella", "label", "roller" };
        List<String> output = List.of("e", "l", "l");
        assertEquals(solution.commonChars(words), output);
    }

    @Test
    public void Example2() {
        String[] words = { "cool", "lock", "cook" };
        List<String> output = List.of("c", "o");
        assertEquals(solution.commonChars(words), output);
    }

}