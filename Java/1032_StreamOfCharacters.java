import java.util.HashMap;
import java.util.Iterator;
import java.util.LinkedList;
import java.util.Map;

class StreamChecker {

    public StreamChecker(String[] words) {
        buildTree(words);
    }

    public boolean query(char letter) {
        stream.add(letter);
        return search();
    }

    private void buildTree(String[] words) {
        for (String word : words) {
            TreeNode node = root;
            boolean isNewNode = true;
            for (int i = word.length() - 1; i >= 0; i--) {
                if (node.children.isEmpty() && !isNewNode) {
                    continue;
                }
                char c = word.charAt(i);
                isNewNode = node.children.putIfAbsent(c, new TreeNode()) == null;;
                node = node.children.get(c);
                if (i == 0) {
                    node.children.clear();
                }
            }
        }
    }

    private boolean search() {
        TreeNode node = root;
        Iterator<Character> revIterator = stream.descendingIterator();
        while (revIterator.hasNext()) {
            node = node.children.get(revIterator.next());
            if (node == null) {
                return false;
            }
            if (node.children.isEmpty()) {
                return true;
            }
        }
        return false;
    }

    private class TreeNode {
        private Map<Character, TreeNode> children = new HashMap<>();
    }

    private TreeNode root = new TreeNode();
    private LinkedList<Character> stream = new LinkedList<>();
}
