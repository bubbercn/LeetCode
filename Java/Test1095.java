import static org.junit.Assert.assertEquals;

import org.junit.Test;

public class Test1095 {
    Solution1095 solution = new Solution1095();

    @Test
    public void Example1() {
        int[] array = { 1, 2, 3, 4, 5, 3, 1 };
        MountainArray mountainArr = new MountainArray(array);
        assertEquals(2, solution.findInMountainArray(3, mountainArr));
    }

    @Test
    public void Example2() {
        int[] array = { 0, 1, 2, 4, 2, 1 };
        MountainArray mountainArr = new MountainArray(array);
        assertEquals(-1, solution.findInMountainArray(3, mountainArr));
    }
}
