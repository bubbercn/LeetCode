import java.util.LinkedList;
import java.util.Collections;
import java.util.Iterator;
import java.util.List;

class Solution1024 {
    public int videoStitching(int[][] clips, int time) {
        List<int[]> clipsList = new LinkedList<>();
        Collections.addAll(clipsList, clips);
        int pos = 0;
        int result = 0;
        while (pos < time) {
            int nextPos = -1;
            Iterator<int[]> iterator = clipsList.iterator();
            while (iterator.hasNext()) {
                int[] clip = iterator.next();
                if (clip[0] <= pos) {
                    nextPos = Math.max(nextPos, clip[1]);
                    iterator.remove();
                }
            }
            if (nextPos == -1)
                return -1;
            pos = nextPos;
            result++;
        }
        return result;
    }
}