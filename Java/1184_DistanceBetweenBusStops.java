class Solution1184 {
    public int distanceBetweenBusStops(int[] distance, int start, int destination) {
        int n = distance.length;
        long totalDistance = 0;
        for (int d : distance) {
            totalDistance += d;
        }
        long clockwiseDistance = 0;
        for (int i = start; i != destination; i = (i + 1) % n) {
            clockwiseDistance += distance[i];
        }
        long counterClockwiseDistance = totalDistance - clockwiseDistance;
        return (int) Math.min(clockwiseDistance, counterClockwiseDistance);
    }
}