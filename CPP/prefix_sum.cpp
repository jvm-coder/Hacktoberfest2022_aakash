/* Demonstrate the concept of prefix sum in a 1d array

Suppose we have an array of N integers. Given Q queries and in each array
we have L and R. The program prints the sum of array elements from L to R

*/

#include <bits/stdc++.h>
using namespace std;

const int SIZE = 1e5+10;
int arr[SIZE];
int pf[SIZE];

class PRE_SUM{
    public:
        PRE_SUM(int n, int arr[]){
            for(int i = 1; i < n; i++){
                pf[i] = pf[i-1] + arr[i]; //Calculates the prefix sum of the 1d array
            }
        }
        void calc(int L, int R){
            cout << "Sum: " << pf[R] - pf[L-1] << endl; //Prints the sum from L to R
        }
};

int main(){
    int size, q;
    cout << "Queries: "; cin >> q;
    cout << "Size: "; cin >> size;
    for(int i = 0; i < size; i++){
        cout << "Element: "; cin >> arr[i];
    }
    pf[0] = arr[0];
    PRE_SUM p(size, arr);
    while(q--){
        int L, R;
        cout << "Enter L and R: "; cin >> L >> R;
        p.calc(L, R);
    }

}