class Solution1011 {
    public int shipWithinDays(int[] weights, int days) {
        int maxWeight = Integer.MIN_VALUE;
        int totalWeight = 0;
        for (int weight : weights) {
            maxWeight = Math.max(maxWeight, weight);
            totalWeight += weight;
        }
        int left = maxWeight;
        int right = totalWeight;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (canShip(weights, days, mid)) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }

    boolean canShip(int[] weights, int days, int capacity) {
        int count = 1;
        int currentWeight = 0;
        for (int weight : weights) {
            currentWeight += weight;
            if (currentWeight > capacity) {
                count++;
                currentWeight = weight;
            }
        }
        return count <= days;
    }
}