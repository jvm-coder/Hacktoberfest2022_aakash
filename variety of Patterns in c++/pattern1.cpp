#include<iostream>
using namespace std;
int main()
{

    int i=1;
    int n;
    cin>>n;
    while(i<=n){
        int j=i;
        while (j<=n)
        {
            cout<<"*";
            j++;
        }
        cout<<endl;
        i++;
    }
// *****
// ****
// ***
// **
// *







    return 0;
}