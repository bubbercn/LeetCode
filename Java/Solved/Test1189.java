import org.junit.Test;
import static org.junit.Assert.assertEquals;
public class Test1189 {
    Solution1189 solution = new Solution1189();

    @Test
    public void Example1() {
        String text = "balloon";
        int expected = 1;
        int result = solution.maxNumberOfBalloons(text);
        assertEquals(expected, result);
    }

    @Test
    public void Example2() {
        String text = "loonbalxballpoon";
        int expected = 2;
        int result = solution.maxNumberOfBalloons(text);
        assertEquals(expected, result);
    }

    @Test
    public void Example3() {
        String text = "abc";
        int expected = 0;
        int result = solution.maxNumberOfBalloons(text);
        assertEquals(expected, result);
    }
}
