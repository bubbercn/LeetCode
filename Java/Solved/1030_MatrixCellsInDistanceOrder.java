import java.util.Arrays;

class Solution1030 {
    public int[][] allCellsDistOrder(int rows, int cols, int rCenter, int cCenter) {
        int[][] result = new int[rows * cols][2];
        for (int i = 0; i < rows * cols; i++) {
            result[i][0] = i / cols;
            result[i][1] = i % cols;
        }
        Arrays.sort(result, (x, y)->(Math.abs(x[0] - rCenter) + Math.abs(x[1] - cCenter)) - (Math.abs(y[0] - rCenter) + Math.abs(y[1] - cCenter)));
        return result;
    }
}