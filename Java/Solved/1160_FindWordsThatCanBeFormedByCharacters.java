class Solution1160 {
    public int countCharacters(String[] words, String chars) {
        int[] charCount = new int[26];
        for (char c : chars.toCharArray()) {
            charCount[c - 'a']++;
        }
        int count = 0;
        for (String word : words) {
            int[] wordCharCount = new int[26];
            boolean canForm = true;
            for (char c : word.toCharArray()) {
                wordCharCount[c - 'a']++;
                if (wordCharCount[c - 'a'] > charCount[c - 'a']) {
                    canForm = false;
                    break;
                }
            }
            if (canForm) {
                count += word.length();
            }
        }
        return count;
    }
}