import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

class Solution1002 {
    public List<String> commonChars(String[] words) {
        int[] lookup = new int[26];
        Arrays.fill(lookup, Integer.MAX_VALUE);
        for (String word : words)
        {
            int[] temp = new int[26];
            for (int i = 0; i < word.length(); i++)
            {
                temp[word.charAt(i) - 'a']++;
            }
            for (int i = 0; i < 26; i++)
            {
                lookup[i] = Math.min(lookup[i], temp[i]);
            }
        }
        List<String> result = new ArrayList<>();
        for (int i = 0; i < 26; i++)
        {
            for (int j = 0; j < lookup[i]; j++)
            {
                result.add(String.valueOf((char)('a' + i)));
            }
        }
        return result;
    }
}