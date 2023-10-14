import static org.junit.Assert.assertEquals;

import org.junit.Test;

public class Test1024 {
    Solution1024 solution = new Solution1024();

    @Test
    public void Example1() {
        int[][] clips = { { 0, 2 }, { 4, 6 }, { 8, 10 }, { 1, 9 }, { 1, 5 }, { 5, 9 } };
        assertEquals(3, solution.videoStitching(clips, 10));
    }

    @Test
    public void Example2() {
        int[][] clips = { { 0, 1 }, { 1, 2 } };
        assertEquals(-1, solution.videoStitching(clips, 5));
    }

    @Test
    public void Example3() {
        int[][] clips = { { 0, 1 }, { 6, 8 }, { 0, 2 }, { 5, 6 }, { 0, 4 }, { 0, 3 }, { 6, 7 }, { 1, 3 }, { 4, 7 },
                { 1, 4 }, { 2, 5 }, { 2, 6 }, { 3, 4 }, { 4, 5 }, { 5, 7 }, { 6, 9 } };
        assertEquals(3, solution.videoStitching(clips, 9));
    }

    @Test
    public void Failure1() {
        int[][] clips = { { 0, 2 }, { 4, 8 } };
        assertEquals(-1, solution.videoStitching(clips, 5));
    }
}
