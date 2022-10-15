#include <bits/stdc++.h>
using namespace std;

int visited[7] = {0, 0, 0, 0, 0, 0, 0};
int graphmapping[7][7] = {
    {0, 1, 1, 1, 0, 0, 0},
    {1, 0, 0, 1, 0, 0, 0},
    {1, 1, 0, 1, 1, 0, 0},
    {1, 0, 1, 0, 1, 0, 0},
    {0, 0, 1, 1, 0, 1, 1},
    {0, 0, 0, 0, 1, 0, 0},
    {0, 0, 0, 0, 1, 0, 0}};

void DFS(int value) // DFS By default it implement the stack data type we can run the program directly also using the recursion procedure.
{
    cout << value << " ";
    visited[value] = 1;
    for (int i = 0; i < 7; i++)
    {
        if (graphmapping[value][i] == 1 && visited[i] == 0) // if the exploration is done and the explored node is unvisited then the for loop will run etc.
        {
            DFS(i); // recursion is used etc.
        }
    } // memory stack is made while using the recursion etc.
}
int main()
{
    DFS(2);
    return 0;
}