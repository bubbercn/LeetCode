import static org.junit.Assert.assertArrayEquals;

import org.junit.Test;

public class Test1054 {
    Solution1054 solution = new Solution1054();

    @Test
    public void Example1() {
        int[] barcodes = { 1, 1, 1, 2, 2, 2 };
        int[] expected = { 1, 2, 1, 2, 1, 2 };
        assertArrayEquals(expected, solution.rearrangeBarcodes(barcodes));
    }

    @Test
    public void Example2() {
        int[] barcodes = { 1, 1, 1, 1, 2, 2, 3, 3 };
        int[] expected = { 1, 2, 1, 2, 1, 3, 1, 3 };
        assertArrayEquals(expected, solution.rearrangeBarcodes(barcodes));
    }

    @Test
    public void Failure1() {
        int[] barcodes = { 1, 1, 2 };
        int[] expected = { 1, 2, 1 };
        assertArrayEquals(expected, solution.rearrangeBarcodes(barcodes));
    }
}
