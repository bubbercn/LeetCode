import java.util.List;
import java.util.ArrayList;
import java.util.Deque;
import java.util.LinkedList;

class Solution1019 {
    public int[] nextLargerNodes(ListNode head) {
        List<Integer> nums = new ArrayList<>();
        while (head != null) {
            nums.add(head.val);
            head = head.next;
        }
        int n = nums.size();
        int[] result = new int[n];
        Deque<Integer> indexes = new LinkedList<>();
        Deque<Integer> values = new LinkedList<>();
        for (int i = 0; i < n; i++) {
            while (!values.isEmpty() && values.peek() < nums.get(i)) {
                result[indexes.pop()] = nums.get(i);
                values.pop();
            }
            indexes.push(i);
            values.push(nums.get(i));
        }
        while (!values.isEmpty()) {
            result[indexes.pop()] = 0;
            values.pop();
        }
        return result;
    }
}