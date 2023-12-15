import java.util.ArrayDeque;
import java.util.HashSet;
import java.util.Set;
import java.util.Queue;

class Solution1036 {
    public boolean isEscapePossible(int[][] blocked, int[] source, int[] target) {
        int n = blocked.length;
        int limit = n * (n - 1) / 2;
        Set<Integer> isBlocked = new HashSet<>();
        for (int[] block : blocked) {
            isBlocked.add(block[0] * MAX + block[1]);
        }
        if (bfs(isBlocked, source, target, limit)) {
            return false;
        }
        return !bfs(isBlocked, target, source, limit);
    }

    private boolean bfs(Set<Integer> isBlocked, int[] source, int[] target, int limit) {
        if (limit == 0) {
            return false;
        }
        int n = 1;
        Set<Integer> visited = new HashSet<>();
        Queue<int[]> next = new ArrayDeque<>();
        next.offer(source);
        visited.add(source[0] * MAX + source[1]);
        while (!next.isEmpty()) {
            int[] cur = next.poll();
            for (int[] dir : DIRS) {
                int x = cur[0] + dir[0];
                int y = cur[1] + dir[1];
                if (x < 0 || x >= MAX || y < 0 || y >= MAX) {
                    continue;
                }
                int key = x * MAX + y;
                if (visited.contains(key)) {
                    continue;
                }
                if (x == target[0] && y == target[1]) {
                    return false;
                }
                if (!isBlocked.contains(key)) {
                    next.offer(new int[] { x, y });
                    visited.add(key);
                    if (++n > limit) {
                        return false;
                    }
                }
            }
        }
        return true;
    }

    private static final int[][] DIRS = { { 0, 1 }, { 0, -1 }, { 1, 0 }, { -1, 0 } };
    private static final int MAX = 1000000;
}