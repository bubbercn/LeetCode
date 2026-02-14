import org.junit.Test;

public class Test1156 {
   Solution1156 solution = new Solution1156();

    @Test
    public void Example1() {
        String text = "ababa";
        Assert.assertEquals(3, solution.maxRepOpt1(text));
    }

    @Test
    public void Example2() {
        String text = "aaabaaa";
        org.junit.Assert.assertEquals(6, solution.maxRepOpt1(text));
    }

    @Test
    public void Example3() {
        String text = "aaabbaaa";
        org.junit.Assert.assertEquals(4, solution.maxRepOpt1(text));
    } 
}
