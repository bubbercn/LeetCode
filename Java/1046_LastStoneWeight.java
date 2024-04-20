import java.util.PriorityQueue;

class Solution1046 {
    public int lastStoneWeight(int[] stones) {
        PriorityQueue<Integer> pq = new PriorityQueue<>((a, b) -> b - a);
        for (int stone : stones) {
            pq.offer(stone);
        }
        while (pq.size() >= 2) {
            int bigger = pq.poll();
            int smaller = pq.poll();
            if (bigger != smaller) {
                pq.offer(bigger - smaller);
            }
        }
        return pq.isEmpty() ? 0 : pq.poll();
    }
}
