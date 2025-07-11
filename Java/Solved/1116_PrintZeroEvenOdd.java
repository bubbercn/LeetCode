import java.util.concurrent.atomic.AtomicBoolean;

class ZeroEvenOdd {
    private int n;

    private AtomicBoolean zero = new AtomicBoolean(true);
    private AtomicBoolean even = new AtomicBoolean(false);

    public ZeroEvenOdd(int n) {
        this.n = n;
    }

    // printNumber.accept(x) outputs "x", where x is an integer.
    public void zero(IntConsumer printNumber) throws InterruptedException {
        for (int i = 0; i < n; i++) {
            while (!zero.get()) {
                Thread.sleep(1);
            }
            printNumber.accept(0);
            zero.set(false);
        }
    }

    public void even(IntConsumer printNumber) throws InterruptedException {
        for (int i = 2; i <= n; i += 2) {
            while (zero.get() || !even.get()) {
                Thread.sleep(1);
            }
            printNumber.accept(i);
            zero.set(true);
            even.set(false);
        }
    }

    public void odd(IntConsumer printNumber) throws InterruptedException {
        for (int i = 1; i <= n; i += 2) {
            while (zero.get() || even.get()) {
                Thread.sleep(1);
            }
            printNumber.accept(i);
            zero.set(true);
            even.set(true);
        }
    }
}