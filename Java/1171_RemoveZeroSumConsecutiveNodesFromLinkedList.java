/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution1171 {
    public ListNode removeZeroSumSublists(ListNode head) {
        int sum = 0;
        ListNode node = head;
        while (node != null) {
            sum += node.val;
            if (sum == 0) {
                head = node.next; // remove from head to current node
                sum = 0; // reset sum
            }
            node = node.next;
        }
        if (head == null) 
            return null;
        head.next = removeZeroSumSublists(head.next);
        return head;
    }
}