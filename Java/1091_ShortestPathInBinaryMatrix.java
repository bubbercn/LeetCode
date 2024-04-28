import java.util.ArrayList;
import java.util.List;

class Solution1091 {
    public int shortestPathBinaryMatrix(int[][] grid) {
        int n = grid.length;
        if (grid[0][0] == 1 || grid[n - 1][n - 1] == 1)
            return -1;
        int step = 2;
        List<Integer> queue = new ArrayList<>();
        queue.add(0);
        int[][] distance = new int[n][n];
        distance[0][0] = 1;
        while (!queue.isEmpty()) {
            List<Integer> next = new ArrayList<>();
            for (int i : queue) {
                int x = i / n;
                int y = i % n;
                if (x == n - 1 && y == n - 1)
                    return distance[x][y];

                for (int[] direction : directions) {
                    int nextX = x + direction[0];
                    int nextY = y + direction[1];
                    if (nextX >= 0 && nextX < n && nextY >= 0 && nextY < n && grid[nextX][nextY] == 0
                            && distance[nextX][nextY] == 0) {
                        next.add(nextX * n + nextY);
                        distance[nextX][nextY] = step;
                    }

                }
            }
            queue = next;
            step++;
        }
        return -1;
    }

    private final int[][] directions = { { -1, -1 }, { -1, 0 }, { -1, 1 }, { 0, -1 }, { 0, 1 }, { 1, -1 }, { 1, 0 },
            { 1, 1 } };
}