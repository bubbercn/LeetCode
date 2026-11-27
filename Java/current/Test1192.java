import static org.junit.Assert.assertEquals;

import java.util.List;

import org.junit.Test;

public class Test1192 {
    Solution1192 solution = new Solution1192();

    @Test
    public void Example1() {
        List<List<Integer>> connections = List.of(
                List.of(0, 1),
                List.of(1, 2),
                List.of(2, 0),
                List.of(1, 3));
        List<List<Integer>> result = solution.criticalConnections(4, connections);
        List<List<Integer>> expected = List.of(
                List.of(1, 3));
        assertEquals(expected, result);
    }

    @Test
    public void Example2() {
        List<List<Integer>> connections = List.of(
                List.of(0, 1));
        List<List<Integer>> result = solution.criticalConnections(2, connections);
        List<List<Integer>> expected = List.of(
                List.of(0, 1));
        assertEquals(expected, result);
    }
}
