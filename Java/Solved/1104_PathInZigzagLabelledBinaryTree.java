import java.util.List;
import java.util.LinkedList;

class Solution1104 {
    public List<Integer> pathInZigZagTree(int label) {
        int begin = 1;
        int end = 1;
        while (end < label) {
            begin = end + 1;
            end = end * 2 + 1;
        }
        List<Integer> result = new LinkedList<>();
        int label2 = begin + end - label;
        boolean useLabel = true;
        while (label > 0 && label2 > 0) {
            if (useLabel) {
                result.addFirst(label);

                useLabel = false;
            } else {
                result.addFirst(label2);
                useLabel = true;
            }
            label /= 2;
            label2 /= 2;
        }
        return result;
    }
}