import java.util.ArrayList;
import java.util.List;

class Solution1073 {
    public int[] addNegabinary(int[] arr1, int[] arr2) {
        int n = arr1.length;
        int m = arr2.length;
        if (n > m) {
            return addNegabinary(arr2, arr1);
        }
        int[] temp = new int[Math.max(n, m) + 2];
        int i = 0;
        for (; i < n; i++) {
            temp[i] += arr1[n - 1 - i] + arr2[m - 1 - i];
            while (temp[i] >= 2) {
                temp[i] -= 2;
                temp[i + 1] -= 1;
            }
            while (temp[i] < 0) {
                temp[i] += 2;
                temp[i + 1] += 1;
            }
        }
        for (; i < m; i++) {
            temp[i] += arr2[m - 1 - i];
            while (temp[i] >= 2) {
                temp[i] -= 2;
                temp[i + 1] -= 1;
            }
            while (temp[i] < 0) {
                temp[i] += 2;
                temp[i + 1] += 1;
            }
        }
        for (; i < temp.length; i++) {
            while (temp[i] >= 2) {
                temp[i] -= 2;
                temp[i + 1] -= 1;
            }
            while (temp[i] < 0) {
                temp[i] += 2;
                temp[i + 1] += 1;
            }
        }

        List<Integer> result = new ArrayList<>();
        boolean start = false;
        for (int j = temp.length - 1; j >= 0; j--) {
            if (temp[j] != 0 && !start) {
                start = true;
            }
            if (start) {
                result.add(temp[j]);
            }
        }
        return result.isEmpty() ? new int[] { 0 } : result.stream().mapToInt(Integer::intValue).toArray();
    }
}