import static org.junit.Assert.assertEquals;

import org.junit.Test;

public class Test1160 {
    Solution1160 solution = new Solution1160();

     @Test
     public void Example1() {
         String[] words = new String[] { "cat", "bt", "hat", "tree" };
         String chars = "atach";
         assertEquals(6, solution.countCharacters(words, chars));
     }

     @Test
     public void Example2() {
         String[] words = new String[] { "hello", "world", "leetcode" };
         String chars = "welldonehoneyr";
         assertEquals(10, solution.countCharacters(words, chars));
     }
}
