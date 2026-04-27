import org.junit.Test;
import static org.junit.Assert.assertEquals;

public class Test1171 {
    Solution1171 solution = new Solution1171();

     @Test
     public void Example1() {
         ListNode head = new ListNode(1, new ListNode(2, new ListNode(-3, new ListNode(3, new ListNode(1)))));
         ListNode expected = new ListNode(3, new ListNode(1));
         assertEquals(expected, solution.removeZeroSumSublists(head));
     }

     @Test
     public void Example2() {
         ListNode head = new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(-3, new ListNode(4)))));
         ListNode expected = new ListNode(1, new ListNode(2, new ListNode(4)));
         assertEquals(expected, solution.removeZeroSumSublists(head));
     }

     @Test
     public void Example3() {
         ListNode head = new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(-3, new ListNode(-2)))));
         ListNode expected = new ListNode(1);
         assertEquals(expected, solution.removeZeroSumSublists(head));
     }
}
