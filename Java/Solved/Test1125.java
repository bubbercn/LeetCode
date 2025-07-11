import static org.junit.Assert.assertArrayEquals;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

import org.junit.Test;

public class Test1125 {
    Solution1125 solution = new Solution1125();

    @Test
    public void Example1() {
        String[] req_skills = new String[] { "java", "nodejs", "reactjs" };
        List<List<String>> people = new ArrayList<>();
        people.add(Arrays.asList("java"));
        people.add(Arrays.asList("nodejs"));
        people.add(Arrays.asList("nodejs", "reactjs"));
        int[] expected = new int[] { 0, 2 };
        assertArrayEquals(expected, solution.smallestSufficientTeam(req_skills, people));
    }

    @Test
    public void Example2() {
        String[] req_skills = new String[] { "algorithms", "math", "java", "reactjs", "csharp", "aws" };
        List<List<String>> people = new ArrayList<>();
        people.add(Arrays.asList("algorithms","math","java"));
        people.add(Arrays.asList("algorithms","math","reactjs"));
        people.add(Arrays.asList("java","csharp","aws"));
        people.add(Arrays.asList("reactjs","csharp"));
        people.add(Arrays.asList("csharp","math"));
        people.add(Arrays.asList("aws","java"));
        int[] expected = new int[] { 1, 2 };
        assertArrayEquals(expected, solution.smallestSufficientTeam(req_skills, people));
    }
}
