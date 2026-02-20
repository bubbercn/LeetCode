import java.util.HashMap;
import java.util.Map;
import java.util.TreeMap;

class SnapshotArray {

    public SnapshotArray(int length) {
        changeMap = new HashMap<>();
        snapData = new TreeMap[length];
        for (int i = 0; i < length; i++) {
            snapData[i] = new TreeMap<>();
        }
    }
    
    public void set(int index, int val) {
        changeMap.put(index, val);
    }
    
    public int snap() {
        for (Map.Entry<Integer, Integer> entry : changeMap.entrySet()) {
            int index = entry.getKey();
            int value = entry.getValue();
            snapData[index].put(snapId, value);
        }
        changeMap.clear();
        return snapId++;
    }
    
    public int get(int index, int snapId) {
        TreeMap<Integer, Integer> map = snapData[index];
        Map.Entry<Integer, Integer> entry = map.floorEntry(snapId);
        return entry != null ? entry.getValue() : 0;
    }

    private TreeMap<Integer, Integer>[] snapData;
    private HashMap<Integer, Integer> changeMap;
    private int snapId = 0;
}