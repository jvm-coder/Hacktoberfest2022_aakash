package DP;

import java.util.Scanner;

public class OccuranceString {

    public static int LCS(String a, String b, int n, int m)
    {
        if(m == 0) return 1;
        if(n == 0) return 0;

        if(a.charAt(n-1) == b.charAt(m-1))
            return LCS(a,b,n-1,m-1) + LCS(a,b,n-1,m);

        else
            return LCS(a,b,n-1,m);
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String a = sc.next();
        String b = sc.next();

        System.out.println("Max Occurrence : " + LCS(a,b,a.length(),b.length()));
    }
}
