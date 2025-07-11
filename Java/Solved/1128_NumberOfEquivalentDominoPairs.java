import java.util.HashMap;
import java.util.Map;

class Solution1128 {
    public int numEquivDominoPairs(int[][] dominoes) {
        Map<Integer, Integer> lookup = new HashMap<>();
        int result = 0;
        for (int i = 0; i < dominoes.length; i++) {
            if (dominoes[i][0] < dominoes[i][1]) {
                int temp = dominoes[i][0];
                dominoes[i][0] = dominoes[i][1];
                dominoes[i][1] = temp;
            }
            int hash = dominoes[i][0] * 10 + dominoes[i][1];
            lookup.put(hash, lookup.getOrDefault(hash, 0) + 1);
        }
        for (int value : lookup.values()) {
            result += value * (value - 1) / 2;
        }
        return result;
    }
}