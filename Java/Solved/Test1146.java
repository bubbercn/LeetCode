import static org.junit.Assert.assertEquals;

import org.junit.Test;

public class Test1146 {
    @Test
    public void Example1() {
        SnapshotArray snapshotArray = new SnapshotArray(3); // set the length to be 3
        snapshotArray.set(0, 5);  // Set array[0] = 5
        assert(snapshotArray.snap() == 0);  // Take a snapshot, returns snap_id = 0
        snapshotArray.set(0, 6);  // Set array[0] = 6
        assertEquals(snapshotArray.get(0, 0), 5);  // Get the value of array[0] with snap_id = 0, return 5
    }    
}
