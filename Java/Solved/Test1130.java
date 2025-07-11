import static org.junit.Assert.assertEquals;
import org.junit.Test;

public class Test1130 {
    Solution1130 solution = new Solution1130();

    @Test
    public void Example1() {
        int[] arr = new int[] { 6, 2, 4 };
        assertEquals(32, solution.mctFromLeafValues(arr));
    }

    @Test
    public void Example2() {
        int[] arr = new int[] { 4, 11 };
        assertEquals(44, solution.mctFromLeafValues(arr));
    }
}
