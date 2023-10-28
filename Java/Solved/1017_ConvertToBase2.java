class Solution1017 {
    public String baseNeg2(int n) {
        StringBuilder result = new StringBuilder();
        while (n != 0) {
            int remainder = n % -2;
            n /= -2;
            if (remainder < 0) {
                remainder += 2;
                n++;
            }
            result.append(remainder);
        }
        return result.length() == 0 ? "0" : result.reverse().toString();
    }
}