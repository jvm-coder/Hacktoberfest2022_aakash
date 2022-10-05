package DP;

import java.util.Scanner;

public class CoinChange {
    public static int coin(int[] arr, int n, int sum)
    {
        if(sum == 0) return 1;

        if(sum < 0) return 0;

        if(n <= 0) return 0;

        return coin(arr,n-1,sum) + coin(arr,n,sum - arr[n-1]);
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt();
        int[] arr = new int[n];

        for(int i=0; i<n; i++) arr[i] = sc.nextInt();
        int sum = sc.nextInt();

        System.out.println("Answer : " + coin(arr,n,sum));

        sc.close();
    }
}