import static org.junit.Assert.assertEquals;

import org.junit.Test;

public class Test1035 {
    Solution1035 solution = new Solution1035();

    @Test
    public void Example1() {
        int[] nums1 = { 1, 4, 2 };
        int[] nums2 = { 1, 2, 4 };
        assertEquals(2, solution.maxUncrossedLines(nums1, nums2));
    }

    @Test
    public void Example2() {
        int[] nums1 = { 2, 5, 1, 2, 5 };
        int[] nums2 = { 10, 5, 2, 1, 5, 2 };
        assertEquals(3, solution.maxUncrossedLines(nums1, nums2));
    }

    @Test
    public void Example3() {
        int[] nums1 = { 1, 3, 7, 1, 7, 5 };
        int[] nums2 = { 1, 9, 2, 5, 1 };
        assertEquals(2, solution.maxUncrossedLines(nums1, nums2));
    }
}
