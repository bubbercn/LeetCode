class Solution1144 {
    public int movesToMakeZigzag(int[] nums) {
        // assume nums[0] > nums[1] < nums[2] > nums[3] ...
        int moves1 = 0;
        for (int i = 1; i < nums.length; i += 2) {
            int temp = Math.min(nums[i - 1], (i + 1 < nums.length ? nums[i + 1] : Integer.MAX_VALUE));
            if (nums[i] >= temp) {
                moves1 += nums[i] - temp + 1;
            }
        }
            
        // assume nums[0] < nums[1] > nums[2] < nums[3] ...
        int moves2 = 0;
        for (int i = 0; i < nums.length; i += 2) {
            int temp = Math.min((i - 1 >= 0 ? nums[i - 1] : Integer.MAX_VALUE), (i + 1 < nums.length ? nums[i + 1] : Integer.MAX_VALUE));
            if (nums[i] >= temp) {
                moves2 += nums[i] - temp + 1;
            }
        }
        return Math.min(moves1, moves2);
    }
}