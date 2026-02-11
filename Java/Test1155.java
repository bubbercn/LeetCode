public class Test1155 {
    Solution1155 solution = new Solution1155();

    @org.junit.Test
    public void Example1() {
        int n = 1, k = 6, target = 3;
        org.junit.Assert.assertEquals(1, solution.numRollsToTarget(n, k, target));
    }

    @org.junit.Test
    public void Example2() {
        int n = 2, k = 6, target = 7;
        org.junit.Assert.assertEquals(6, solution.numRollsToTarget(n, k, target));
    }

    @org.junit.Test
    public void Example3() {
        int n = 30, k = 30, target = 500;
        org.junit.Assert.assertEquals(222616187, solution.numRollsToTarget(n, k, target));
    }
}
