import java.util.LinkedList;

class Solution1081 {
    public String smallestSubsequence(String s) {
        int[] count = new int[26];
        boolean[] used = new boolean[26];
        for (int i = 0; i < s.length(); i++) {
            count[s.charAt(i) - 'a']++;
        }
        LinkedList<Integer> stack = new LinkedList<>();
        for (int i = 0; i < s.length(); i++) {
            int index = s.charAt(i) - 'a';
            count[index]--;
            if (used[index]) {
                continue;
            }
            while (!stack.isEmpty() && stack.getLast() > index && count[stack.getLast()] > 0) {
                used[stack.removeLast()] = false;
            }
            stack.addLast(index);
            used[index] = true;
        }
        StringBuilder result = new StringBuilder();
        for (int i : stack) {
            result.append((char) (i + 'a'));
        }
        return result.toString();
    }
}