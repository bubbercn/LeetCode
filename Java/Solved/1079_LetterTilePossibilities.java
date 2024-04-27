class Solution1079 {
    public int numTilePossibilities(String tiles) {
        int[] count = new int[26];
        for (int i = 0; i < tiles.length(); i++) {
            count[tiles.charAt(i) - 'A']++;
        }
        return dfs(count);
    }

    private int dfs(int[] count) {
        int result = 0;
        for (int i = 0; i < 26; i++) {
            if (count[i] == 0)
                continue;
            result++;
            count[i]--;
            result += dfs(count);
            count[i]++;
        }
        return result;
    }
}