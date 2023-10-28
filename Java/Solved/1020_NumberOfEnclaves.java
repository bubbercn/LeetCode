import java.util.LinkedList;
import java.util.Queue;

class Solution1020 {
    public int numEnclaves(int[][] grid) {
        int m = grid.length;
        int n = grid[0].length;
        Queue<int[]> q = new LinkedList<>();
        for (int i = 0; i < m; i++) {
            if (grid[i][0] == 1) {
                grid[i][0] = 0;
                q.add(new int[] { i, 0 });
            }
            if (grid[i][n - 1] == 1) {
                grid[i][n - 1] = 0;
                q.add(new int[] { i, n - 1 });
            }
        }
        for (int j = 0; j < n; j++) {
            if (grid[0][j] == 1) {
                grid[0][j] = 0;
                q.add(new int[] { 0, j });
            }
            if (grid[m - 1][j] == 1) {
                grid[m - 1][j] = 0;
                q.add(new int[] { m - 1, j });
            }
        }
        while (!q.isEmpty()) {
            int[] curr = q.poll();
            int i = curr[0];
            int j = curr[1];
            for (int[] direction : directions) {
                int x = i + direction[0];
                int y = j + direction[1];
                if (x >= 0 && x < m && y >= 0 && y < n && grid[x][y] == 1) {
                    grid[x][y] = 0;
                    q.add(new int[] { x, y });
                }
            }
        }
        int result = 0;
        for (int i = 1; i < m - 1; i++) {
            for (int j = 1; j < n - 1; j++)
                if (grid[i][j] == 1)
                    result++;
        }
        return result;
    }

    private static final int[][] directions = new int[][] { { 0, 1 }, { 0, -1 }, { 1, 0 }, { -1, 0 } };
}