import static org.junit.Assert.assertEquals;

import java.util.List;

import org.junit.Test;

public class Test1096 {
    Solution1096 solution = new Solution1096();

    @Test
    public void Example1() {
        List<String> expected = List.of("ac", "ad", "ae", "bc", "bd", "be");
        assertEquals(expected, solution.braceExpansionII("{a,b}{c,{d,e}}"));
    }

    @Test
    public void Example2() {
        List<String> expected = List.of("a", "ab", "ac", "z");
        assertEquals(expected, solution.braceExpansionII("{{a,z},a{b,c},{ab,z}}"));
    }
}
