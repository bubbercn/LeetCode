import static org.junit.Assert.assertEquals;

import org.junit.Test;

public class Test1019 {
    Solution1019 solution = new Solution1019();

    @Test
    public void Example1() {
        int[] nums = new int[] { 2, 1, 5 };
        ListNode head = new ListNode(nums[0]);
        ListNode current = head;
        for (int i = 1; i < nums.length; i++) {
            current.next = new ListNode(nums[i]);
            current = current.next;
        }
        int[] output = new int[] { 5, 5, 0 };
        assertEquals(solution.nextLargerNodes(head), output);
    }

    @Test
    public void Example2() {
        int[] nums = new int[] { 2, 7, 4, 3, 5 };
        ListNode head = new ListNode(nums[0]);
        ListNode current = head;
        for (int i = 1; i < nums.length; i++) {
            current.next = new ListNode(nums[i]);
            current = current.next;
        }
        int[] output = new int[] { 7, 0, 5, 5, 0 };
        assertEquals(solution.nextLargerNodes(head), output);
    }
}
