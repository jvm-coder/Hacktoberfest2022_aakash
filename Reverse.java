
import java.util.Scanner;

public class Reverse {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int num = in.nextInt();
//        int num = 23597;
        int ans = 0;

        while (num>0){
            int rem = num % 10;
            num /= 10;

            ans = ans * 10 + rem;

        }

        System.out.println(ans);
    }
}
