#include<iostream>
using namespace std;
int main(){
    int i=1;
    int n;
    cin>>n;
    while (i<=n)
    {
        int j=1;
        int val=1;
        while(j<=i)
        {
            cout<<val;
            
            j++;
        }
        cout<<endl;
        i++;
    }
     




    return 0;
}