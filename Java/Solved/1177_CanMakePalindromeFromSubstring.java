import java.util.ArrayList;
import java.util.List;

class Solution1177 {
    public List<Boolean> canMakePaliQueries(String s, int[][] queries) {
        int [][] prefixCount = new int[26][s.length() + 1];
        for (int i = 0; i < s.length(); i++) {
            for (int j = 0; j < 26; j++) {
                prefixCount[j][i + 1] = prefixCount[j][i];
            }
            prefixCount[s.charAt(i) - 'a'][i + 1]++;
        }
        List<Boolean> result = new ArrayList<>();
        for (int[] query : queries) {
            int left = query[0];
            int right = query[1];
            int k = query[2];
            result.add(canMakePalindrome(prefixCount, left, right, k));
        }
        return result;
    }

    private boolean canMakePalindrome(int[][] prefixCount, int left, int right, int k) {
        int[] charCount = new int[26];
        for (int i = 0; i < 26; i++) {
            charCount[i] = prefixCount[i][right + 1] - prefixCount[i][left];
        }
        int oddCount = 0;
        for (int count : charCount) {
            if (count % 2 != 0) {
                oddCount++;
            }
        }
        return oddCount / 2 <= k;
    }
}
