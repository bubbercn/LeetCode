class Solution1089 {
    public void duplicateZeros(int[] arr) {
        int count = 0;
        for (int i : arr) {
            if (i == 0) {
                count++;
            }
        }
        int n = arr.length;
        for (int i = n - 1; i >= 0; i--) {
            if (i + count < n) {
                arr[i + count] = arr[i];
            }
            if (arr[i] == 0) {
                count--;
                if (i + count < n) {
                    arr[i + count] = 0;
                    if (i + count + 1 < n)
                        arr[i + count + 1] = 0;
                }
            }
        }
    }
}