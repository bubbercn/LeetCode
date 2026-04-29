import static org.junit.Assert.assertEquals;

import java.util.List;

import org.junit.Test;

public class Test1178 {
    Solution1178 solution = new Solution1178();

    @Test
    public void Example1() {
        String[] words = { "aaaa", "asas", "able", "ability", "actt", "actor", "access" };
        String[] puzzles = { "aboveyz", "abrodyz", "abslute", "absoryz", "actresz", "gaswxyz" };
        List<Integer> expected = List.of(1, 1, 3, 2, 4, 0);
        assertEquals(expected, solution.findNumOfValidWords(words, puzzles));
    }

    @Test
    public void Example2() {
        String[] words = { "apple", "pleas", "please" };
        String[] puzzles = { "aelwxyz", "aelpxyz", "aelpsxy", "saelpxy", "xaelpsy" };
        List<Integer> expected = List.of(0, 1, 3, 2, 0);
        assertEquals(expected, solution.findNumOfValidWords(words, puzzles));
    }
}
