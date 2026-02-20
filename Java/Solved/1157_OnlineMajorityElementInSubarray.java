import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

class MajorityChecker {

    public MajorityChecker(int[] arr) {
        indexMap = new HashMap<>();
        array = arr;
        for (int i = 0; i < arr.length; i++) {
            indexMap.computeIfAbsent(arr[i], k -> new ArrayList<>()).add(i);
        }
    }
    
    public int query(int left, int right, int threshold) {
        for (int i = 0; i < MAX_TRY; i++) {
            int index = left + (int) (Math.random() * (right - left + 1));
            int value = array[index];
            List<Integer> indexes = indexMap.get(value);
            int count = countInRange(indexes, left, right);
            if (count >= threshold) {
                return value;
            }
        }
        return -1;
    }

    private int countInRange(List<Integer> indexes, int left, int right) {
        int l = java.util.Collections.binarySearch(indexes, left);
        int r = java.util.Collections.binarySearch(indexes, right);
        if (l < 0) l = -l - 1;
        if (r < 0) r = -r - 2;
        return r - l + 1;
    }

    private Map<Integer, List<Integer>> indexMap = new HashMap<>();
    private int[] array;
    private static final int MAX_TRY = 20;
}