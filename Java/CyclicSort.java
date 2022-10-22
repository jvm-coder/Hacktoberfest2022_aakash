import java.util.Arrays;

public class CyclicSort {
    public static void main(String[] args) {
        int[] arr= {4, 5, 1, 2, 3};
        
        cyclic(arr);
        System.out.println(Arrays.toString(arr));

    }

    static void swap(int[] arr, int a, int b) {
        int temp = arr[a];
        arr[a] = arr[b];
        arr[b] = temp;
    }

    static void cyclic(int[] arr) {
        int i = 0;
        while (i < arr.length) {
            if(arr[i] == i + 1) {
                i++;
                continue;
            }
            swap(arr, i, arr[i] - 1);
        }
    }
}
