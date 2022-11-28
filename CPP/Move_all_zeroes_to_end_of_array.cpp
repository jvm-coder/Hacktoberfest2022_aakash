// C++ program to shift all zeros
// to right most side of array
// without affecting order of non-zero
// elements.
 
#include <bits/stdc++.h>
using namespace std;
// function to shift zeros
void move_zeros_to_right(vector<int>& m)
{
    int count = 0;
    for (int i = 0; i < m.size(); i++) {
        if (m[i] == 0) {
            count++;
            // deleting the element from vector
            m.erase(m.begin() + i);
            i--;
        }
    }
 
    for (int i = 0; i < count; i++) {
        // inserting the zero into vector
        m.push_back(0);
    }
    cout << "array after shifting zeros to right side: "
         << endl;
    for (int i = 0; i < m.size(); i++) {
        // printing desired vector
        cout << m[i] << " ";
    }
}
// driver code
int main()
{
    vector<int> m{ 5, 6, 0, 4, 6, 0, 9, 0, 8 };
    // function call
    move_zeros_to_right(m);
    return 0;
}