import java.util.Arrays;

class Solution1170 {
    public int[] numSmallerByFrequency(String[] queries, String[] words) {
        int[] wordFreqs = new int[words.length];
        for (int i = 0; i < words.length; i++) {
            wordFreqs[i] = f(words[i]);
        }

        Arrays.sort(wordFreqs);

        int n = wordFreqs.length;
        int[] result = new int[queries.length];
        for (int i = 0; i < queries.length; i++) {
            int queryFreq = f(queries[i]);
            int pos = Arrays.binarySearch(wordFreqs, queryFreq + 1);
            int idx;
            if (pos >= 0) {
                // find first occurrence of value >= queryFreq+1
                while (pos > 0 && wordFreqs[pos - 1] == wordFreqs[pos]) pos--;
                idx = pos;
            } else {
                idx = -pos - 1; // insertion point
            }
            result[i] = n - idx; // words with freq > queryFreq
        }
        return result;
    }

    private int f(String s) {
        char smallest = 'z';
        int count = 0;
        for (char c : s.toCharArray()) {
            if (c < smallest) {
                smallest = c;
                count = 1;
            } else if (c == smallest) {
                count++;
            }
        }
        return count;
    }

    // Uses Arrays.binarySearch above; no custom upperBound needed.
}
