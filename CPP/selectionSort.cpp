#include <bits/stdc++.h>
using namespace std;

void selectionSort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int min_ind = i;
        for (int j = i; j < n; j++)
            if (arr[j] < arr[min_ind])
                min_ind = j;
        swap(arr[i], arr[min_ind]);
    }
}
void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}
int main()
{
    int arr[] = {5, 4, 2, 3, 1};
    selectionSort(arr, 5);
    printArray(arr, 5);
}