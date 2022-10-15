
#include<iostream>
#include <fstream>

// Function to print the output 
void printTheArray(int arr[], int n, std::ofstream* out) { 
    for (int i = 0; i < n; i++) { 
        *out << arr[i] << ","; 
    } 
    *out << std::endl; 
} 
  
// Function to generate all binary strings 
void generateAllBinaryStrings(int n, int arr[], int i, std::ofstream* out) { 
    if (i == n) { 
        printTheArray(arr, n, out); 
        return; 
    } 

    arr[i] = 0; 
    generateAllBinaryStrings(n, arr, i + 1, out); 

    arr[i] = 1; 
    generateAllBinaryStrings(n, arr, i + 1, out); 
} 
  
// Driver Code 
int main() { 
    int n = 8; 
  
    int arr[n]; 
    std::ofstream out("combos.csv", std::ofstream::out);;
    // Print all binary strings 
    generateAllBinaryStrings(n, arr, 0, &out); 
  
    return 0; 
}
