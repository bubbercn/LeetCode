import static org.junit.Assert.assertEquals;

import java.util.List;

import org.junit.Test;

public class Test1169 {
    Solution1169 solution = new Solution1169();

    @Test
    public void Example1() {
        String[] transactions = {"alice,20,800,mtv", "alice,50,100,beijing"};
        List<String> expected = List.of("alice,20,800,mtv", "alice,50,100,beijing");
        assertEquals(expected, solution.invalidTransactions(transactions));
    }

    @Test
    public void Example2() {
        String[] transactions = {"bob,1200,1000,mtv"};
        List<String> expected = List.of("bob,1200,1000,mtv");
        assertEquals(expected, solution.invalidTransactions(transactions));
    }

    @Test
    public void Example3() {
        String[] transactions = {"alex,676,260,bangkok","bob,656,350,bangkok","alex,676,261,bangkok"};
        List<String> expected = List.of("alex,676,260,bangkok","bob,656,350,bangkok");
        assertEquals(expected, solution.invalidTransactions(transactions));
    }
}
