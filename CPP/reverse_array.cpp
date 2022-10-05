#include<iostream>
using namespace std;
 
int main(){

    int arr[] = {1,2,3,4,5,6,7,8,9};
    int n = 9;   // size of arr

    // Reverse array
    for(int i=0;i<n/2;i++){
        int temp = arr[i];
        arr[i] = arr[n-1-i];
        arr[n-1-i] = temp;
    }

    // Print array
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
 
   return 0;
}