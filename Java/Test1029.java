import static org.junit.Assert.assertEquals;

import org.junit.Test;

public class Test1029 {
    Solution1029 solution1029 = new Solution1029();

    @Test
    public void Example1() {
        int[][] costs = {{10, 20}, {30, 200}, {400, 50}, {30, 20}};
        assertEquals(110, solution1029.twoCitySchedCost(costs));
    }

    @Test
    public void Example2() {
        int[][] costs = {{259, 770}, {448, 54}, {926, 667}, {184, 139}, {840, 118}, {577, 469}};
        assertEquals(1859, solution1029.twoCitySchedCost(costs));
    }

    @Test
    public void Example3() {
        int[][] costs = {{515, 563}, {451, 713}, {537, 709}, {343, 819}, {855, 779}, {457, 60}, {650, 359}, {631, 42}};
        assertEquals(3086, solution1029.twoCitySchedCost(costs));
    }
}
