import static org.junit.Assert.assertEquals;

import org.junit.Test;

public class Test1172 {
        @Test
        public void Example1() {
            DinnerPlates obj = new DinnerPlates(2);
            obj.push(1);
            obj.push(2);
            obj.push(3);
            obj.push(4);
            obj.push(5);
            assertEquals(2, obj.popAtStack(0));
            obj.push(20);
            obj.push(21);
            assertEquals(20, obj.popAtStack(0));
            assertEquals(21, obj.pop());
            assertEquals(4, obj.pop());
        }
}
