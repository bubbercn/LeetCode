class Solution1111 {
    public int[] maxDepthAfterSplit(String seq) {
        int[] result = new int[seq.length()];
        int currentDepth = 0;
        for (int i = 0; i < seq.length(); i++) {
            if (seq.charAt(i) == '(') {
                result[i] = currentDepth & 1;
                currentDepth++;
            } else {
                currentDepth--;
                result[i] = currentDepth & 1;
            }
        }
        return result;
    }
}