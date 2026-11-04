import org.junit.Test;
import static org.junit.Assert.assertEquals;
import static org.junit.Assert.assertArrayEquals;

public class Test1171 {
    Solution1171 solution = new Solution1171();

     @Test
     public void Example1() {
         ListNode head = new ListNode(1, new ListNode(2, new ListNode(-3, new ListNode(3, new ListNode(1)))));
         int[] expected = {3,1};
         assertArrayEquals(expected, toArray(solution.removeZeroSumSublists(head)));
     }

     @Test
     public void Example2() {
         ListNode head = new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(-3, new ListNode(4)))));
         int[] expected = {1,2,4};
         assertArrayEquals(expected, toArray(solution.removeZeroSumSublists(head)));
     }

     @Test
     public void Example3() {
         ListNode head = new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(-3, new ListNode(-2)))));
         int[] expected = {1};
         assertArrayEquals(expected, toArray(solution.removeZeroSumSublists(head)));

    }

    private int[] toArray(ListNode head) {
        java.util.List<Integer> vals = new java.util.ArrayList<>();
        ListNode cur = head;
        while (cur != null) {
            vals.add(cur.val);
            cur = cur.next;
        }
        int[] a = new int[vals.size()];
        for (int i = 0; i < vals.size(); i++) a[i] = vals.get(i);
        return a;
     }
}
