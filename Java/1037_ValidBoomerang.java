import java.util.Arrays;

class Solution1037 {
    public boolean isBoomerang(int[][] points) {
        if (Arrays.equals(points[0], points[1]) || Arrays.equals(points[1], points[2]) || Arrays.equals(points[0], points[2]))
            return false;
        if (points[0][0] == points[1][0] && points[1][0] == points[2][0])
            return false;
        
        return (points[2][1] - points[0][1]) * (points[1][0] - points[0][0]) != (points[1][1] - points[0][1]) * (points[2][0] - points[0][0]);
    }
}