import static org.junit.Assert.assertEquals;

import org.junit.Test;

public class Test1157 {
    @Test
    public void example1() {
        MajorityChecker majorityChecker = new MajorityChecker(new int[] { 1, 1, 2, 2, 1, 1 });
        assertEquals(1, majorityChecker.query(0, 5, 4));
        assertEquals(-1, majorityChecker.query(0, 3, 3));
        assertEquals(2, majorityChecker.query(2, 3, 2));
    }

    @Test
    public void Failure1() {
        MajorityChecker majorityChecker = new MajorityChecker(new int[] { 2,2,1,2,1,2,2,1,1,2 });
        assertEquals(-1, majorityChecker.query(2, 5, 4));
        assertEquals(-1, majorityChecker.query(0, 5, 6));
        assertEquals(2, majorityChecker.query(0, 1, 2));
        assertEquals(-1, majorityChecker.query(2, 3, 2));
        assertEquals(2, majorityChecker.query(6, 6, 1));
        assertEquals(2, majorityChecker.query(0, 3, 3));
        assertEquals(-1, majorityChecker.query(4, 9, 6));
        assertEquals(-1, majorityChecker.query(4, 8, 4));
        assertEquals(-1, majorityChecker.query(5, 9, 5));
        assertEquals(2, majorityChecker.query(0, 1, 2));
    }
}
