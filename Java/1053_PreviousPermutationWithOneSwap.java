import java.util.Arrays;

class Solution1053 {
    public int[] prevPermOpt1(int[] arr) {
        int n = arr.length;
        for (int i = n - 2; i >= 0; i--) {
            if (arr[i] > arr[i + 1]) {
                int pos = Arrays.binarySearch(arr, i + 1, n, arr[i]);
                pos = pos < 0 ? -pos - 1 : pos;
                while (arr[pos - 1] == arr[pos - 2]) {
                    pos--;
                }
                int temp = arr[i];
                arr[i] = arr[pos - 1];
                arr[pos - 1] = temp;
                return arr;
            }
        }
        return arr;
    }
}