import java.util.concurrent.atomic.AtomicBoolean;

class FooBar {
    private int n;

    public FooBar(int n) {
        this.n = n;
    }

    public void foo(Runnable printFoo) throws InterruptedException {
        
        for (int i = 0; i < n; i++) {
            while (!foo.get()) {
                Thread.sleep(1);
            }
        	// printFoo.run() outputs "foo". Do not change or remove this line.
        	printFoo.run();
            foo.set(false);
        }
    }

    public void bar(Runnable printBar) throws InterruptedException {
        
        for (int i = 0; i < n; i++) {
            while (foo.get()) {
                Thread.sleep(1);
            }
            // printBar.run() outputs "bar". Do not change or remove this line.
        	printBar.run();
            foo.set(true);
        }
    }

    private AtomicBoolean foo = new AtomicBoolean(true);
}