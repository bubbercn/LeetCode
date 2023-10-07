import static org.junit.Assert.assertEquals;

import java.util.ArrayList;
import java.util.Arrays;

import org.junit.Test;

public class Test1018 {
    Solution1018 solution = new Solution1018();

    @Test
    public void Example1() {
        int[] nums = new int[] { 0, 1, 1 };
        ArrayList<Boolean> output = new ArrayList<Boolean>(Arrays.asList(true, false, false));
        assertEquals(solution.prefixesDivBy5(nums), output);
    }

    @Test
    public void Example2() {
        int[] nums = new int[] { 1, 1, 1 };
        ArrayList<Boolean> output = new ArrayList<Boolean>(Arrays.asList(false, false, false));
        assertEquals(solution.prefixesDivBy5(nums), output);
    }
}
