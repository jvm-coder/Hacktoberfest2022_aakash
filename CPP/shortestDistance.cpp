//Shortest Distance in a Binary Maze
// Given a n * m matrix grid where each element can either be 0 or 1. You need to find the shortest distance between a given source cell to a 
// destination cell. The path can only be created out of a cell if its value is 1. 
// If the path is not possible between source cell and destination cell, then return -1.
// Note : You can move into an adjacent cell if that adjacent cell is filled with element 1. Two cells are adjacent if 
// they share a side. In other words, you can move in one of the four directions, Up, Down, Left and Right.


// METHOD - 1
//using Backtracking and recursion
//T.C. : O(4^MN)
//S.C. : O(MN)
class Solution {
  public:
  void dfs(int i,int j,int m,int n,int x2,int y2,vector<vector<int>>&grid,vector<vector<int>>&vis,int &mind,int dist){
      if(i<0 || j<0 || i>=m || j>=n)
      return ;
      if(i==x2 && j==y2) {
          mind = min(mind,dist);
          return;
      }
      if(grid[i][j] == 0) return ;
      if(vis[i][j] == 1) return ;
      if(grid[i][j] == 1 && vis[i][j] == 0){
      vis[i][j] = 1;
    
    dfs(i+1,j,m,n,x2,y2,grid,vis,mind,dist+1);
    dfs(i-1,j,m,n,x2,y2,grid,vis,mind,dist+1);
  dfs(i,j-1,m,n,x2,y2,grid,vis,mind,dist+1);
  dfs(i,j+1,m,n,x2,y2,grid,vis,mind,dist+1);
      }
      vis[i][j] = 0;
      
  }
   int shortestPath(vector<vector<int>> &grid, pair<int, int> source,
                    pair<int, int> destination) {
        code here
        int m = grid.size();
        int n = grid[0].size();
        int x1 = source.first, y1 = source.second;
        int x2 = destination.first, y2 = destination.second;
        vector<vector<int>> vis(m,vector<int>(n,0));
        int dist = INT_MAX;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i== x1 && j == y1 && vis[i][j]==0){
                dfs(i,j,m,n,x2,y2,grid,vis,dist,0);
                }
            }
        }
      if(dist!=INT_MAX)
      return dist;
      return -1;
    }

    // METHOD - 2
    //using BFS
    //T.C. : O(n * m)
    //S.C. : O(n * m)
class Solution {
  public:
  int shortestPath(vector<vector<int>> &grid, pair<int, int> source,pair<int, int> destination) {

        // code here

        queue<pair<int,int>>q;

        q.push({source.first,source.second});

        int ans=0;

        int n=grid.size();

        int m=grid[0].size();

        while(!q.empty()){

            int sz=q.size();

            while(sz--){

                auto f=q.front();

                q.pop();

                if(f.first==destination.first && f.second==destination.second)

                    return ans;

                int x=f.first;

                int y=f.second;

                grid[x][y]=0;

                if(x-1>=0 && grid[x-1][y]==1){

                    grid[x-1][y]=0;

                    q.push({x-1,y});

                }

                if(x+1<n && grid[x+1][y]==1){

                    grid[x+1][y]=0;

                    q.push({x+1,y});

                }

                if(y-1>=0 && grid[x][y-1]==1){

                    grid[x][y-1]=0;

                    q.push({x,y-1});

                }

                if(y+1<m && grid[x][y+1]==1){

                    grid[x][y+1]=0;

                    q.push({x,y+1});

                }
                }
                ans++;
                }
   return -1;
   }
};