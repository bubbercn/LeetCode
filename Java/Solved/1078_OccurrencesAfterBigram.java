import java.util.LinkedList;

class Solution1078 {
    public String[] findOcurrences(String text, String first, String second) {
        String[] words = text.split(" ");
        LinkedList<String> result = new LinkedList<>();
        for (int i = 0; i < words.length; i++) {
            if (i + 2 < words.length && words[i].equals(first) && words[i + 1].equals(second)) {
                result.add(words[i + 2]);
            }
        }
        return result.toArray(new String[result.size()]);
    }
}