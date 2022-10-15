#include <bits/stdc++.h>
using namespace std;
void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}
void insertionSort(int arr[], int n)
{
    for (int i = 1; i < n; i++)
    {
        int j = i - 1, key = arr[i];
        while (j >= 0 and key < arr[j])
        {
            arr[j + 1] = arr[j];
            j -= 1;
        }

        arr[j + 1] = key;
        if (i == 5)
        {
            printArray(arr, n);
            break;
        }
    }
}

int main()
{
    int arr[] = {28, 35, 12, 15, 27, 11, 9, 14, 8, 32};
    insertionSort(arr, 5);
    printArray(arr, 5);
}