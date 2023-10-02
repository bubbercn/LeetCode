import java.util.HashMap;
import java.util.HashSet;

class Solution1001 {
    public int[] gridIllumination(int n, int[][] lamps, int[][] queries) {
        HashSet<Long> lampLookup = new HashSet<>();
        HashMap<Integer, Integer> vertical = new HashMap<>();
        HashMap<Integer, Integer> horizontal = new HashMap<>();
        HashMap<Integer, Integer> diagonal1 = new HashMap<>();
        HashMap<Integer, Integer> diagonal2 = new HashMap<>();
        for (int[] lamp : lamps) {
            Long hash = hash(lamp[0], lamp[1]);
            if (lampLookup.add(hash) == false)
                continue;
            vertical.put(lamp[0], vertical.getOrDefault(lamp[0], 0) + 1);
            horizontal.put(lamp[1], horizontal.getOrDefault(lamp[1], 0) + 1);
            diagonal1.put(lamp[0] + lamp[1], diagonal1.getOrDefault(lamp[0] + lamp[1], 0) + 1);
            diagonal2.put(lamp[0] - lamp[1], diagonal2.getOrDefault(lamp[0] - lamp[1], 0) + 1);
        }
        int[] result = new int[queries.length];
        for (int i = 0; i < queries.length; i++) {
            int x = queries[i][0];
            int y = queries[i][1];
            if (vertical.getOrDefault(x, 0) > 0 || horizontal.getOrDefault(y, 0) > 0
                    || diagonal1.getOrDefault(x + y, 0) > 0 || diagonal2.getOrDefault(x - y, 0) > 0) {
                result[i] = 1;
            }
            for (int j = x - 1; j <= x + 1; j++) {
                for (int k = y - 1; k <= y + 1; k++) {
                    if (j < 0 || j >= n || k < 0 || k >= n)
                        continue;
                    Long hash = hash(j, k);
                    if (lampLookup.remove(hash)) {
                        vertical.put(j, vertical.getOrDefault(j, 0) - 1);
                        horizontal.put(k, horizontal.getOrDefault(k, 0) - 1);
                        diagonal1.put(j + k, diagonal1.getOrDefault(j + k, 0) - 1);
                        diagonal2.put(j - k, diagonal2.getOrDefault(j - k, 0) - 1);
                    }
                }
            }
        }
        return result;
    }

    private long hash(int x, int y) {
        return (long) x << 32 | y;
    }
}