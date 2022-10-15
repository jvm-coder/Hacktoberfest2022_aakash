package DP;

import java.util.*;

public class FrequencyOfCharacters {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        String str = sc.nextLine();

        int[] arr = new int[26];
        Arrays.fill(arr,0);

        for(int i=0; i<str.length(); i++)
        {
            char ch = str.charAt(i);
            arr[ch - 'a'] += 1;
        }

        for(int i=0; i<26; i++)
        {
            if(arr[i] != 0) {
                System.out.print((char) ('a' + i));
                System.out.print(" - " + arr[i] + "\n");
            }
        }

        sc.close();
    }
}
