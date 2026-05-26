import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

class Solution1178 {
    public List<Integer> findNumOfValidWords(String[] words, String[] puzzles) {
        // Count frequency of each word bitmask
        Map<Integer, Integer> wordFreq = new HashMap<>();
        for (String word : words) {
            int mask = 0;
            for (char c : word.toCharArray()) {
                mask |= 1 << (c - 'a');
            }
            wordFreq.merge(mask, 1, Integer::sum);
        }
    
        List<Integer> result = new ArrayList<>();
        for (String puzzle : puzzles) {
            int puzzleMask = 0;
            for (char c : puzzle.toCharArray()) {
                puzzleMask |= 1 << (c - 'a');
            }
            int firstBit = 1 << (puzzle.charAt(0) - 'a');
            int count = 0;
            // Enumerate all subsets of puzzleMask that include firstBit
            // Start from puzzleMask and remove bits one by one (subset enumeration trick)
            for (int sub = puzzleMask; sub != 0; sub = (sub - 1) & puzzleMask) {
                if ((sub & firstBit) != 0) {
                    count += wordFreq.getOrDefault(sub, 0);
                }
            }
            result.add(count);
        }
        return result;
    }
}