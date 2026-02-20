class Solution1139 {
    public int largest1BorderedSquare(int[][] grid) {
        int m = grid.length;
        int n = grid[0].length;
        int edgeLength = Math.min(m, n);
        while (edgeLength > 0) {
            for (int i = 0; i <= m - edgeLength; i++) {
                for (int j = 0; j <= n - edgeLength; j++) {
                    if (isBorderedSquare(grid, i, j, edgeLength)) {
                        return edgeLength * edgeLength;
                    }
                }
            }
            edgeLength--;
        }
        return 0;
    }

    private boolean isBorderedSquare(int[][] grid, int row, int col, int len) {
        for (int i = 0; i < len; i++) {
            if (grid[row][col + i] == 0 || grid[row + len - 1][col + i] == 0 ||
                grid[row + i][col] == 0 || grid[row + i][col + len - 1] == 0) {
                return false;
            }
        }
        return true;
    }
}