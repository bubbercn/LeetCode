import static org.junit.Assert.assertFalse;
import static org.junit.Assert.assertTrue;

import org.junit.Test;

public class Test1032 {
    @Test
    public void Example1() {
        String[] words = { "cd", "f", "kl" };
        StreamChecker streamChecker = new StreamChecker(words);
        assertFalse(streamChecker.query('a'));
        assertFalse(streamChecker.query('b'));
        assertFalse(streamChecker.query('c'));
        assertTrue(streamChecker.query('d'));
        assertFalse(streamChecker.query('e'));
        assertTrue(streamChecker.query('f'));
        assertFalse(streamChecker.query('g'));
        assertFalse(streamChecker.query('h'));
        assertFalse(streamChecker.query('i'));
        assertFalse(streamChecker.query('j'));
        assertFalse(streamChecker.query('k'));
        assertTrue(streamChecker.query('l'));
    }
}
