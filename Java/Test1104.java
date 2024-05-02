import org.junit.Test;
import static org.junit.Assert.assertEquals;
import java.util.List;

public class Test1104 {
    Solution1104 solution = new Solution1104();

    @Test
    public void Example1() {
        List<Integer> expected = List.of(1, 3, 4, 14);
        assertEquals(expected, solution.pathInZigZagTree(14));
    }

    @Test
    public void Example2() {
        List<Integer> expected = List.of(1, 2, 6, 10, 26);
        assertEquals(expected, solution.pathInZigZagTree(26));
    }
}
