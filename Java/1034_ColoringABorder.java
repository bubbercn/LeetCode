import java.util.LinkedList;
import java.util.List;

class Solution1034 {
    public int[][] colorBorder(int[][] grid, int row, int col, int color) {
        List<int[]> cur = new LinkedList<>();
        cur.add(new int[] { row, col });
        List<int[]> border = new LinkedList<>();
        int m = grid.length;
        int n = grid[0].length;
        boolean[][] visited = new boolean[m][n];

        while (!cur.isEmpty()) {
            List<int[]> next = new LinkedList<>();
            for (int[] p : cur) {
                if (visited[p[0]][p[1]])
                    continue;
                boolean isBorder = false;
                for (int[] dir : dirs) {
                    int x = p[0] + dir[0];
                    int y = p[1] + dir[1];
                    if (x < 0 || x >= m || y < 0 || y >= n) {
                        isBorder = true;
                        continue;
                    }
                    if (grid[x][y] == grid[p[0]][p[1]]) {
                        next.add(new int[] { x, y });
                    } else {
                        isBorder = true;
                    }
                }
                if (isBorder) {
                    border.add(p);
                }
                visited[p[0]][p[1]] = true;
            }
            cur = next;
        }
        for (int[] p : border) {
            grid[p[0]][p[1]] = color;
        }
        return grid;
    }

    private final int[][] dirs = { { 0, 1 }, { 0, -1 }, { 1, 0 }, { -1, 0 } };
}