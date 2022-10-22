
public class threads {

    public static void main(String[] args) {
        long start = System.currentTimeMillis();

        // print the results, what fib() output
        System.out.println("fib(12): " + fib(12));
        System.out.println("fib(17): " + fib(17));

        // since we execute on the main thread
        // this statement is only executed when the
        // above two fib() function call finishes

        System.out.println("Took " + (System.currentTimeMillis() - start) + "ms");

        new Thread(() -> {
            System.out.println("fib(14): " + fib(14));
            System.out.println("fib(19): " + fib(19));
        }).start();

        // this statement is called, but the recursive
        // algorithm is running on another thread
        System.out.println("Wait, It's still running!");
    }
    private static int fib(int n) {
        if (n < 2) {
            return n;
        }
        return fib(n - 1) + fib(n - 2);
    }
}