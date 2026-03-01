import java.util.ArrayList;
import java.util.List;

class Solution1162 {
    public int maxDistance(int[][] grid) {
        List<List<Integer>> next = new ArrayList<>();
        for (int i = 0; i < grid.length; i++) {
            for (int j = 0; j < grid[0].length; j++) {
                if (grid[i][j] == 1) {
                    next.add(List.of(i, j));
                }
            }
        }
        int result = -1;
        while (!next.isEmpty()) {
            List<List<Integer>> newNext = new ArrayList<>();
            for (List<Integer> cell : next) {
                for (int[] direction : DIRECTIONS) {
                    int x = cell.get(0) + direction[0];
                    int y = cell.get(1) + direction[1];
                    if (x >= 0 && x < grid.length && y >= 0 && y < grid[0].length
                            && grid[x][y] == 0) {
                        grid[x][y] = 1;
                        newNext.add(List.of(x, y));
                    }
                }
            }
            next = newNext;
            result++;
        }
        return result == 0 ? -1 : result;
    }

    private static final int[][] DIRECTIONS = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
}