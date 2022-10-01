
import java.util.Scanner;

public class Fibonacci {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int n = in.nextInt();
        int a = 0;
        int b = 1;
        int count = 2;  // we already have first two numbers

        while (count <= n) {
            int temp = b;
            b = b + a;
            a = temp;     //why temp = bcoz if i take a=b here the value will not be the prev b but the one that's
                          // updated by b=b+a
            count++;
        }
        System.out.println(b);
    }
}
