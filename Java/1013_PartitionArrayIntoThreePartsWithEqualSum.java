import java.util.Arrays;

class Solution1013 {
    public boolean canThreePartsEqualSum(int[] arr) {
        int sum = 0;
        for (int i : arr)
            sum += i;
        if (sum % 3 != 0)
            return false;

        int target = sum / 3;
        int count = 0;
        int currentSum = 0;
        int temp = arr.length - 1;
        for (int i = 0; i < temp; i++) {
            currentSum += arr[i];
            if (currentSum == target) {
                count++;
                if (count == 2)
                    return true;
                currentSum = 0;
            }
        }
        return false;
    }
}