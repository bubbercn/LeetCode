import java.util.HashMap;
import java.util.Map;
import java.util.Arrays;

class Solution1090 {
    class Element {
        int value;
        int label;

        Element(int value, int label) {
            this.value = value;
            this.label = label;
        }
    }

    public int largestValsFromLabels(int[] values, int[] labels, int numWanted, int useLimit) {
        Map<Integer, Integer> labelUsed = new HashMap<>();
        Integer[] ids = new Integer[values.length];
        for (int i = 0; i < values.length; i++) {
            ids[i] = i;
        }
        Arrays.sort(ids, (a, b) -> values[b] - values[a]);
        int result = 0;
        for (Integer id : ids) {
            int label = labels[id];
            int value = values[id];
            if (labelUsed.getOrDefault(label, 0) < useLimit){
                result += value;
                numWanted--;
                labelUsed.put(label, labelUsed.getOrDefault(label, 0) + 1);
                if (numWanted == 0)
                    break;
            }
        }
        return result;
    }
}