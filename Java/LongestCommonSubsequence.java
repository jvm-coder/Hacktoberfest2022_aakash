package DP;

import java.util.*;

public class LongestCommonSubsequence {

    public static int Lcs(String a, String b, int n, int m)
    {
        if(n==0 || m==0) return 0;

        if(a.charAt(n-1) == b.charAt(m-1))
            return 1 + Lcs(a,b,n-1,m-1);

        else
        {
            int x = Lcs(a,b,n,m-1);
            int y = Lcs(a,b,n-1,m);
            return x>y ? x : y;
        }

    }

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);

        String str1 = sc.nextLine();
        String str2 = sc.nextLine();
        int n = str1.length();
        int m = str2.length();

        int length = Lcs(str1, str2, n, m);

        System.out.print("Longest common subsequence : " + length);

        sc.close();
    }
}
