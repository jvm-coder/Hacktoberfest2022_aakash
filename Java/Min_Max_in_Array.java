import java.util.Arrays;

public class Min_Max_in_Array {

    static void MinMax(int arr[]) {
        int max = arr[0];
        int min = arr[0];

        //Time Complexity = O(n)
        for (int i = 0; i < arr.length; i++) {
            if (max < arr[i]) {
                max = arr[i];
            }

            if (min > arr[i]) {
                min = arr[i];
            }
        }

        System.out.println("Minimum in Array : " + min);
        System.out.println("Maximum in Array : " + max);

        //Time Complexity = O(nlogn)

//        Arrays.sort(arr);
//        min = arr[0];
//        max = arr[arr.length-1];


    }

    public static void main(String[] args) {

        int[] arr = {10, 20, 30, 40, 50};
        MinMax(arr);

    }
}
