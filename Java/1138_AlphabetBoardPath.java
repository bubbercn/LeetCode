import java.util.HashMap;
import java.util.Map;

class Solution1138 {
    public String alphabetBoardPath(String target) {
        Map<Character, int[]> positionMap = new HashMap<>();
        // Fill the position map for alphabet board
        for (int i = 0; i < 26; i++) {
            char ch = (char) ('a' + i);
            int row = i / 5;
            int col = i % 5;
            positionMap.put(ch, new int[] { row, col });
        }

        StringBuilder path = new StringBuilder();
        int[] currentPos = { 0, 0 };

        for (char c : target.toCharArray()) {
            int[] targetPos = positionMap.get(c);
            path.append(getMovePath(currentPos, targetPos));
            path.append("!");
            currentPos = targetPos.clone();
        }

        return path.toString();
    }

    private String getMovePath(int[] from, int[] to) {
        StringBuilder moves = new StringBuilder();
        int verticalMoves = to[0] - from[0];
        int horizontalMoves = to[1] - from[1];

        if (to[0] == 5) {
            addHorizontalMoves(moves, horizontalMoves);
            addVerticalMoves(moves, verticalMoves);
        } else {
            addVerticalMoves(moves, verticalMoves);
            addHorizontalMoves(moves, horizontalMoves);
        }

        return moves.toString();
    }

    private void addVerticalMoves(StringBuilder moves, int verticalMoves) {
        if (verticalMoves < 0) {
            moves.append("U".repeat(-verticalMoves));
        } else if (verticalMoves > 0) {
            moves.append("D".repeat(verticalMoves));
        }
    }

    private void addHorizontalMoves(StringBuilder moves, int horizontalMoves) {
        if (horizontalMoves < 0) {
            moves.append("L".repeat(-horizontalMoves));
        } else if (horizontalMoves > 0) {
            moves.append("R".repeat(horizontalMoves));
        }
    }
}