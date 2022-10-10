#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int arraysum(int arr[], int n)
{
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum = sum + arr[i];
    }
    return sum;
}

int main()
{
    int size;
    cout << "Enter size of array:";
    cin >> size;
    int arr[size];
    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }
    cout << "Sum of all elements of array is : " << arraysum(arr, size);

    return 0;
}
