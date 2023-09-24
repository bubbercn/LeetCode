import java.util.BitSet;

class Solution1009 {
    public int bitwiseComplement(int n) {
        BitSet bs = toBitSet(n);
        if (bs.isEmpty()) {
            return 1;
        }
        bs.flip(0, bs.length());
        return toInt(bs);
    }

    private BitSet toBitSet(int n) {
        BitSet bs = new BitSet();
        int i = 0;
        while (n > 0) {
            if (n % 2 == 1) {
                bs.set(i);
            }
            n /= 2;
            i++;
        }
        return bs;
    }

    private int toInt(BitSet bs) {
        int n = 0;
        for (int i = 0; i < 32; i++) {
            if (bs.get(i)) {
                n += Math.pow(2, i);
            }
        }
        return n;
    }
}