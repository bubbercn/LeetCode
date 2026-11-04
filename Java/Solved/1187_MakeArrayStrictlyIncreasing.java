import java.util.Arrays;
import java.util.Map;
import java.util.HashMap;
import java.util.TreeSet;
import java.util.stream.Collectors;

class Solution1187 {
    public int makeArrayIncreasing(int[] arr1, int[] arr2) {
        TreeSet<Integer> set2 = Arrays.stream(arr2).boxed().collect(Collectors.toCollection(TreeSet::new));
        Map<Integer, Integer> states = new HashMap<>();
        states.put(arr1[0], 0);
        int replace = getMinGreater(set2, -1);
        if (replace != -1 && replace < arr1[0]) {
            states.put(replace, 1);
        }
        for (int i = 1; i < arr1.length; i++) {
            Map<Integer, Integer> newStates = new HashMap<>();
            for (Map.Entry<Integer, Integer> entry : states.entrySet()) {
                int prev = entry.getKey();
                int cost = entry.getValue();
                if (arr1[i] > prev) {
                    newStates.put(arr1[i], Math.min(newStates.getOrDefault(arr1[i], Integer.MAX_VALUE), cost));
                }
                replace = getMinGreater(set2, prev);
                if (replace != -1) {
                    newStates.put(replace, Math.min(newStates.getOrDefault(replace, Integer.MAX_VALUE), cost + 1));
                }
            }
            states = newStates;
            if (states.isEmpty()) {
                return -1;
            }
        }
        return states.values().stream().min(Integer::compare).orElse(-1);
    }

    private int getMinGreater(TreeSet<Integer> set, int val) {
        Integer next = set.higher(val);
        return next == null ? -1 : next;
    }
}