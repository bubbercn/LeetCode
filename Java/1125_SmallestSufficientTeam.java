import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;

class Solution1125 {
    public int[] smallestSufficientTeam(String[] req_skills, List<List<String>> people) {
        int n = req_skills.length;
        HashMap<String, Integer> skill2Int = new HashMap<>();
        for (int i = 0; i < n; i++) {
            skill2Int.put(req_skills[i], i);
        }
        int m = people.size();
            
        List<Integer>[] dp = new List[1 << n];
        dp[0] = List.of();
        for (int i = 0; i < m; i++) {
            int skill = 0;
            for (String s : people.get(i)) {
                skill |= 1 << skill2Int.get(s);
            }
            for (int j = 0; j < dp.length; j++) {
                if (dp[j] == null) {
                    continue;
                }
                int next = j | skill;
                if (dp[next] == null || dp[next].size() > dp[j].size() + 1) {
                    dp[next] = new ArrayList<>(dp[j]);
                    dp[next].add(i);
                }
            }
        }
        return dp[(1 << n) - 1].stream().mapToInt(i -> i).toArray();
    }
}