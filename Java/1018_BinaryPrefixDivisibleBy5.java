import java.util.ArrayList;
import java.util.List;

class Solution1018 {
    public List<Boolean> prefixesDivBy5(int[] nums) {
        List<Boolean> result = new ArrayList<Boolean>();
        int value = 0;
        for (int num : nums) {
            value = ((value << 1) + num) % 5;
            result.add(value == 0);
        }
        return result;
    }
}