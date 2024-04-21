import java.util.HashMap;
import java.util.HashSet;
import java.util.Map;
import java.util.Set;

class Solution1042 {
    public int[] gardenNoAdj(int n, int[][] paths) {
        Map<Integer, Set<Integer>> graph = new HashMap<>();
        int[] colors = new int[n];
        for (int[] path : paths) {
            int a = path[0];
            int b = path[1];
            graph.putIfAbsent(a, new HashSet<>());
            graph.putIfAbsent(b, new HashSet<>());
            graph.get(a).add(b);
            graph.get(b).add(a);
        }
        for (int i = 1; i <= n; i++) {
            var neighborColors = graph.get(i);
            if (neighborColors == null) {
                colors[i - 1] = 1;
            } else {
                colors[i - 1] = getUnusedColor(neighborColors, colors);
            }
        }
        return colors;
    }

    private int getUnusedColor(Set<Integer> neighborColors, int[] colors) {
        Set<Integer> usedColors = new HashSet<>();
        for (int neighbor : neighborColors) {
            int c = colors[neighbor - 1];
            if (c != 0) {
                usedColors.add(c);
            }
        }
        for (int i = 1; i <= 4; i++) {
            if (!usedColors.contains(i)) {
                return i;
            }
        }
        return -1;
    }
}