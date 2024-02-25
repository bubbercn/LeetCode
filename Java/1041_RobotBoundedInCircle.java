class Solution1041 {
    public boolean isRobotBounded(String instructions) {
        int dir = 0;
        int x = 0, y = 0;
        for (int i = 0; i < instructions.length(); i++) {
            if (instructions.charAt(i) == 'G') {
                x += directions[dir][0];
                y += directions[dir][1];
            } else if (instructions.charAt(i) == 'L') {
                dir = (dir + 1) % 4;
            } else {
                dir = (dir + 3) % 4;
            }
        }
        return dir != 0 || (x == 0 && y == 0);
    }

    private static final int[][] directions = new int[][] { { 0, 1 }, { -1, 0 }, { 0, -1 }, { 1, 0 } };
}