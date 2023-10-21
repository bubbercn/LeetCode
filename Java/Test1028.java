import org.junit.Test;

public class Test1028 {
    Solution1028 solution = new Solution1028();

    @Test
    public void Example1() {
        String traversal = "1-2--3--4-5--6--7";
        solution.recoverFromPreorder(traversal);
    }

    @Test
    public void Example2() {
        String traversal = "1-2--3---4-5--6---7";
        solution.recoverFromPreorder(traversal);
    }

    @Test
    public void Example3() {
        String traversal = "1-401--349---90--88";
        solution.recoverFromPreorder(traversal);
    }
}
