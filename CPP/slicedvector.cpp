#include "bits/stdc++.h"
using namespace std;
 
// Function to slice a given vector
// from range X to Y
vector<int> slicing(vector<int>& arr,
                    int X, int Y)
{
 
    // Starting and Ending iterators
    auto start = arr.begin() + X;
    auto end = arr.begin() + Y + 1;
 
    // To store the sliced vector
    vector<int> result(Y - X + 1);
 
    // Copy vector using copy function()
    copy(start, end, result.begin());
 
    // Return the final sliced vector
    return result;
}
 
// Function to print the vector ans
void printResult(vector<int>& ans)
{
 
    // Traverse the vector ans
    for (auto& it : ans) {
 
        // Print elements
        cout << it << ' ';
    }
}
 
// Driver Code
int main()
{
 
    // Given vector
    vector<int> arr = { 1, 3, 4, 2,
                        4, 2, 1 };
 
    // Given range
    int X = 2, Y = 5;
 
    // Function Call
    vector<int> ans;
    ans = slicing(arr, X, Y);
 
    // Print the sliced vector
    printResult(ans);
}
