class DisjointSet {
    private int[] parent;
    public DisjointSet(int n) {
        parent = new int[n];
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    public int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    public void merge(int x1, int x2) {
        int m1 = find(x1);
        int m2 = find(x2);
        if (m1 < m2) {
            parent[m2] = m1;
        } else {
            parent[m1] = m2;
        }
    }
}

class Solution1061 {
    public String smallestEquivalentString(String s1, String s2, String baseStr) {
        DisjointSet ds = new DisjointSet(26);
        for (int i = 0; i < s1.length(); i++) {
            char c1 = s1.charAt(i);
            char c2 = s2.charAt(i);
            ds.merge(c1 - 'a', c2 - 'a');
        }
        // iterate through the baseStr and find the smallest equivalent character
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < baseStr.length(); i++) {
            char c = baseStr.charAt(i);
            char smallest = (char) ('a' + ds.find(c - 'a'));
            sb.append(smallest);
        }
        return sb.toString();
    }
}