import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.SortedMap;
import java.util.TreeMap;

class Solution1054 {
    public int[] rearrangeBarcodes(int[] barcodes) {
        Map<Integer, Integer> count = new HashMap<>();
        for (int barcode : barcodes) {
            count.put(barcode, count.getOrDefault(barcode, 0) + 1);
        }

        SortedMap<Integer, List<Integer>> sortedCount = new TreeMap<>((a, b) -> b - a);
        for (Map.Entry<Integer, Integer> entry : count.entrySet()) {
            if (!sortedCount.containsKey(entry.getValue())) {
                sortedCount.put(entry.getValue(), new ArrayList<>());
            }
            sortedCount.get(entry.getValue()).add(entry.getKey());
        }

        List<Integer> sortedBarcodes = new ArrayList<>();
        for (Map.Entry<Integer, List<Integer>> entry : sortedCount.entrySet()) {
            for (int barcode : entry.getValue()) {
                for (int i = 0; i < entry.getKey(); i++) {

                    sortedBarcodes.add(barcode);
                }
            }
        }

        int[] result = new int[barcodes.length];
        for (int i = 0; i < barcodes.length / 2; i++) {
            result[i * 2] = sortedBarcodes.get(i);
            result[i * 2 + 1] = sortedBarcodes.get(i + (barcodes.length + 1) / 2);
        }
        if (barcodes.length % 2 == 1) {
            result[barcodes.length - 1] = sortedBarcodes.get(barcodes.length / 2);
        }
        return result;
    }
}