import java.util.Arrays;

class Solution1122 {
    public int[] relativeSortArray(int[] arr1, int[] arr2) {
        int[] order = new int[1001];
        for (int i = 0; i < arr2.length; i++) {
            order[arr2[i]] = i + 1;
        }
        // convert to arr1 to Integer[]
        Integer[] arr1Integer = Arrays.stream(arr1).boxed().toArray(Integer[]::new);
        Arrays.sort(arr1Integer, (a, b) -> {
            if (order[a] == 0 && order[b] == 0) {
                return a - b;
            } else if (order[a] == 0) {
                return 1;
            } else if (order[b] == 0) {
                return -1;
            } else {
                return order[a] - order[b];
            }
        });
        // convert back to int[]
        for (int i = 0; i < arr1Integer.length; i++) {
            arr1[i] = arr1Integer[i];
        }
        return arr1;
    }
}