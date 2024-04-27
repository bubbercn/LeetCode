import java.util.HashMap;
import java.util.Map;

class Solution1072 {
    public int maxEqualRowsAfterFlips(int[][] matrix) {
        int result = 0;
        Map<String, Integer> map = new HashMap<>();
        int m = matrix.length;
        int n = matrix[0].length;
        for (int i = 0; i < m; i++) {
            StringBuilder sb = new StringBuilder();
            int[] temp = matrix[i];
            boolean reverse = (temp[0] == 1);
            for (int j = 0; j < n; j++) {
                if (reverse) {
                    sb.append(1 - temp[j]);
                } else {
                    sb.append(temp[j]);
                }
            }
            String key = sb.toString();
            map.put(key, map.getOrDefault(key, 0) + 1);
            result = Math.max(result, map.get(key));
        }
        return result;
    }
}