import static org.junit.Assert.assertEquals;

import org.junit.Test;

public class Test1157 {
    @Test
    public void Example1() {
        MajorityChecker majorityChecker = new MajorityChecker(new int[] { 1, 1, 2, 2, 1, 1 });
        assertEquals(1, majorityChecker.query(0, 5, 4));
        assertEquals(-1, majorityChecker.query(0, 3, 3));
        assertEquals(2, majorityChecker.query(2, 3, 2));
    }
}
