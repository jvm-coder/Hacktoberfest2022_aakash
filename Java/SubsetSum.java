package DP;

import java.util.*;

public class SubsetSum {

    public static boolean Subset(int[] arr, int n, int w)
    {
        if(n==0) return false;
        if(w==0) return true;

        if(w < arr[n-1]) return Subset(arr,n-1,w);

        else return Subset(arr,n-1,w) || Subset(arr,n-1, w-arr[n-1]);
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt();
        int[] arr = new int[n];

        for(int i=0; i<n; i++) arr[i] = sc.nextInt();

        int w = sc.nextInt();

        System.out.print(Subset(arr,n,w));

    }
}
