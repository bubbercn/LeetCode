import java.util.concurrent.atomic.AtomicInteger;

class Foo {

    public Foo() {
        
    }

    public void first(Runnable printFirst) throws InterruptedException {
        
        // printFirst.run() outputs "first". Do not change or remove this line.
        printFirst.run();
        current.incrementAndGet();
    }

    public void second(Runnable printSecond) throws InterruptedException {
        
        // printSecond.run() outputs "second". Do not change or remove this line.
        while (current.get() != 1) {
            Thread.sleep(1);
        }
        printSecond.run();
        current.incrementAndGet();
    }

    public void third(Runnable printThird) throws InterruptedException {
        
        // printThird.run() outputs "third". Do not change or remove this line.
        while (current.get() != 2) {
            Thread.sleep(1);
        }
        printThird.run();
    }

    private AtomicInteger current = new AtomicInteger(0);
}