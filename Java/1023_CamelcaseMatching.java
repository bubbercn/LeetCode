import java.util.ArrayList;
import java.util.List;

class Solution1023 {
    public List<Boolean> camelMatch(String[] queries, String pattern) {
        List<Boolean> result = new ArrayList<>();
        for (String query : queries) {
            result.add(isMatch(query, pattern));
        }
        return result;
    }

    private Boolean isMatch(String query, String pattern) {
        int patternIndex = 0;
        for (int i = 0; i < query.length(); i++) {
            if (patternIndex < pattern.length()) {
                if (query.charAt(i) == pattern.charAt(patternIndex)) {
                    patternIndex++;
                } else if (Character.isUpperCase(query.charAt(i))) {
                    return false;
                }
            } else {
                if (Character.isUpperCase(query.charAt(i))) {
                    return false;
                }
            }
        }
        return patternIndex == pattern.length();
    }
}