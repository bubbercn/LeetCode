import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashSet;
import java.util.Set;

class Solution1129 {
    public int[] shortestAlternatingPaths(int n, int[][] redEdges, int[][] blueEdges) {
        Map<Integer, List<Integer>> redLookup = new HashMap<>();
        Map<Integer, List<Integer>> blueLookup = new HashMap<>();
        for (int i = 0; i < redEdges.length; i++) {
            int from = redEdges[i][0];
            int to = redEdges[i][1];
            redLookup.putIfAbsent(from, new ArrayList<>());
            redLookup.get(from).add(to);
        }
        for (int i = 0; i < blueEdges.length; i++) {
            int from = blueEdges[i][0];
            int to = blueEdges[i][1];
            blueLookup.putIfAbsent(from, new ArrayList<>());
            blueLookup.get(from).add(to);
        }
        Set<Integer> toVisit = new HashSet<>();
        toVisit.add(0);
        toVisit.add(1);
        Set<Integer> visited = new HashSet<>();
        visited.add(0);
        visited.add(1);
        int distance = 0;
        int[] result = new int[n];
        Arrays.fill(result, -1);
        while (!toVisit.isEmpty()) {
            Set<Integer> nextToVisit = new HashSet<>();
            for (Integer value : toVisit) {
                visited.add(value);
                int currentNode = value /2;
                int prevColor = value % 2;
                if (result[currentNode] == -1 || result[currentNode] > distance) {
                    result[currentNode] = distance;
                } 
                var lookup = prevColor == 0 ? blueLookup : redLookup;
                List<Integer> neighbors = lookup.getOrDefault(currentNode, new ArrayList<>());
                for (Integer neighbor : neighbors) {
                    int nextValue = neighbor * 2 + (prevColor == 0 ? 1 : 0);
                    if (!visited.contains(nextValue)) {
                        nextToVisit.add(nextValue);
                    }
                }
            }
            toVisit = nextToVisit;
            distance++;
        }
        return result;
    }
}