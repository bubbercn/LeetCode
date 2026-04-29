class Solution1175 {
    public int numPrimeArrangements(int n) {
        int primeCount = 0;
        for (int i = 1; i <= n; i++) {
            if (isPrime(i)) {
                primeCount++;
            }
        }
        int result = 1;
        for (int i = 1; i <= primeCount; i++) {
            result = (int) ((long) result * i % MOD);
        }
        for (int i = 1; i <= n - primeCount; i++) {
            result = (int) ((long) result * i % MOD);
        }
        return result;
    }

    private boolean isPrime(int n) {
        if (n <= 1) {
            return false;
        }
        for (int i = 2; i * i <= n; i++) {
            if (n % i == 0) {
                return false;
            }
        }
        return true;
    }

    private final int MOD = 1_000_000_007;
}