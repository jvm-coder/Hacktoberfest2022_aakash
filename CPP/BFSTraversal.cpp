#include<unordered_map>
#include<set>
#include<queue>
#include<vector>
using namespace std;
//list prepare kro
void prepareAdjList(unordered_map<int,set<int>> &adjList,vector<pair<int, int>> &edges){
    for(int i=0; i<edges.size(); i++){
        int u = edges[i].first;
        int v = edges[i].second;
        
        adjList[u].insert(v);
        adjList[v].insert(u);
    }
}

//bfs Function
void bfs(unordered_map<int,set<int>> &adjList,unordered_map<int,bool> &visited,vector<int> &ans, int node){
    //ek queue bnao
    queue<int> q;
    q.push(node);
    //mark it visited
    visited[node] = 1;
    
    while(!q.empty()){
        //ek front Node bnao
        int frontNode = q.front();
        q.pop();
        ans.push_back(frontNode);
        
        //traverse neighbours
        for(auto i:adjList[frontNode]){
            if(!visited[i]){
                q.push(i);
                visited[i] = 1;
            }
        }
    }
    
}

vector<int> BFS(int vertex, vector<pair<int, int>> edges)
{
   //isme adjacency list bhi khud bna ni hogi toh lets goo
    unordered_map<int,set<int>> adjList;
    vector<int> ans;
    unordered_map<int,bool> visited;
    prepareAdjList(adjList,edges);
    //ab traverse karo all components ko
    for(int i=0; i<vertex; i++){
        if(!visited[i]){
            bfs(adjList,visited,ans,i);
        }
    }
    return ans;
   
}